#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100


// Graph data structure
typedef struct {
    int vertices[MAX_VERTICES];
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int incidenceMatrix[MAX_VERTICES][MAX_EDGES];
    int numVertices;
} Graph;

// Stack data structure for DFS
typedef struct {
    int data[MAX_VERTICES];
    int top;
} Stack;

// Functions for graph operations
void initializeGraph(Graph* graph, int numVertices) {
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        graph->vertices[i] = 0;
        for (int j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* graph, int source, int destination) {
    graph->adjacencyMatrix[source][destination] = 1;
    graph->adjacencyMatrix[destination][source] = 1;
}

void displayVertex(int vertex) {
    printf("%d ", vertex);
}

void depthFirstSearch(Graph* graph, int startVertex) {
    Stack stack;
    stack.top = -1;
    bool visited[MAX_VERTICES] = { false };

    // Push the starting vertex onto the stack
    stack.data[++stack.top] = startVertex;

    while (stack.top != -1) {
        // Pop a vertex from the stack
        int currentVertex = stack.data[stack.top--];

        // Visit the current vertex if not visited before
        if (!visited[currentVertex]) {
            displayVertex(currentVertex);
            visited[currentVertex] = true;
        }

        // Push all unvisited adjacent vertices onto the stack
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                stack.data[++stack.top] = i;
            }
        }
    }
}


int main() {
    // Initialize the graph
    Graph graph;
    int numVertices ;
    printf("enter the number of vertices");
    scanf("%d",&numVertices );
    initializeGraph(&graph, numVertices);

    // Generate random edges
    srand(time(NULL));
    int numEdges = rand() % (numVertices * (numVertices - 1) / 2) + 1;  // Random number of edges between 1 and n*(n-1)/2
    for (int i = 0; i < numEdges; i++)
    {
        int source = rand() % numVertices;
        int destination = rand() % numVertices;
        addEdge(&graph, source, destination);
    }
        printf("%d",numEdges );

    printf("Generated Graph (Adjacency Matrix):\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", graph.adjacencyMatrix[i][j]);
        }
        printf("\n");
    }


    int startVertex = rand() % numVertices;
    printf("\nDepth First Search (DFS) starting from vertex %d: ", startVertex);
    depthFirstSearch(&graph, startVertex);

    return 0;
}
