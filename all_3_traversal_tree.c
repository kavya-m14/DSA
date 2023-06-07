#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

                                                             // Creation(node)
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

                                                             // Insertion(node)
struct Node* insert(struct Node* root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

                                                             //pre-order traversal.
void preOrder(struct Node* root, FILE* file)
{
    if (root != NULL)
    {
        fprintf(file, "%d ", root->data);
        preOrder(root->left, file);
        preOrder(root->right, file);
    }
}

                                                             //post-order traversal.
void postOrder(struct Node* root, FILE* file)
{
    if (root != NULL)
    {
        postOrder(root->left, file);
        postOrder(root->right, file);
        fprintf(file, "%d ", root->data);
    }
}

                                                             //in-order traversal.
void inOrder(struct Node* root, FILE* file)
{
    if (root != NULL)
    {
        inOrder(root->left, file);
        fprintf(file, "%d ", root->data);
        inOrder(root->right, file);
    }
}

int main()
{
    clock_t start,end;
    double totalT;

                                                                // Generate random numbers and store them in a file.
    FILE* inputFile = fopen("randomN.txt", "w");
    if (inputFile == NULL)
    {
        printf("Error opening file.");
        return 1;
    }
    srand(time(NULL));

                                                             // Generate 10 random numbers and store them in the file.
    for (int i = 0; i < 6; i++)
    {
        int randomNumber = rand() % 100;
        fprintf(inputFile, "%d ", randomNumber);
    }
    fclose(inputFile);

                                                             // Reading generated random numbers from the file.
    FILE* inputFileRead = fopen("randomN.txt", "r");
    if (inputFileRead == NULL)
    {
        printf("Error opening file.");
        return 1;
    }

    struct Node* root = NULL;
    int data;

    while (fscanf(inputFileRead, "%d", &data) != EOF)       //Insert them into TREE.
    {
        root = insert(root, data);
    }
    fclose(inputFileRead);

                                                            //Traversal operations and store the results in separate files.
    FILE* preOrderFile = fopen("pre_order.txt", "w");
    if (preOrderFile == NULL)
    {
        printf("Error opening file.");
        return 1;
    }
    totalT=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nTime Complexity for preOrder : %lf",totalT);
    preOrder(root, preOrderFile);
    fclose(preOrderFile);



    FILE* postOrderFile = fopen("post_order.txt", "w");
    if (postOrderFile == NULL)
    {
        printf("Error opening file.");
        return 1;
    }
    totalT=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nTime Complexity for postOrder: %lf",totalT);
    postOrder(root, postOrderFile);
    fclose(postOrderFile);



    FILE* inOrderFile = fopen("in_order.txt", "w");
    if (inOrderFile == NULL)
    {
        printf("Error opening file.");
        return 1;
    }
    inOrder(root, inOrderFile);
    fclose(inOrderFile);
    totalT=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nTime Complexity for inOrder  : %lf",totalT);
    return 0;
}

