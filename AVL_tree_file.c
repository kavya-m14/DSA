#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};

// Function to get the height of a node
int height(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // New node is initially added at the leaf level
    return node;
}

// Function to right rotate a subtree rooted with y
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return the new root
    return x;
}

// Function to left rotate a subtree rooted with x
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return the new root
    return y;
}

// Function to get the balance factor of a node
int getBalance(struct Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Function to insert a node into the AVL tree
struct Node* insert(struct Node* node, int key) {
    // Perform the normal BST insertion
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Duplicate keys are not allowed in AVL tree
        return node;

    // Update the height of the ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // Check the balance factor and perform rotations if needed
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
}

// Function to print the AVL tree in an inorder traversal
void inorder(struct Node* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->key);
        inorder(node->right);
    }
}

// Function to write the AVL tree to the output file in an inorder traversal
void inorderToFile(struct Node* node, FILE* outputFile) {
    if (node != NULL) {
        inorderToFile(node->left, outputFile);
        fprintf(outputFile, "%d ", node->key);
        inorderToFile(node->right, outputFile);
    }
}

// Driver program
int main() {
    struct Node* root = NULL;

    // Open the input and output files
    FILE* inputFile = fopen("input_avl.txt", "r");
    FILE* outputFile = fopen("output_avl.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    int key;
    // Read keys from the input file and insert them into the AVL tree
    while (fscanf(inputFile, "%d", &key) != EOF) {
        root = insert(root, key);
    }

    // Print the AVL tree to the console
    printf("Inorder traversal of the AVL tree: ");
    inorder(root);

    // Write the AVL tree to the output file
    inorderToFile(root, outputFile);

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
