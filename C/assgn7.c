#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 1000

// Structure to represent a node in the adjacency list
typedef struct Graph_Node {
    int dest;
    int weight;
    struct Graph_Node* next;
} Graph_Node;

// Structure to represent the adjacency list
typedef struct AdjList {
    Graph_Node* head;
} AdjList;

// Structure to represent the graph
typedef struct Graph {
    int numVertices;
    AdjList array[MAX_VERTICES];
} Graph;

// Structure to represent a node in the min-heap
typedef struct MinHeapNode {
    int vertex;
    int distance;
} MinHeapNode;

// Structure to represent the min-heap
typedef struct MinHeap {
    int size;
    int heap_capacity;
    int* pos;
    MinHeapNode** array;
} MinHeap;

// Function to create a new node in the adjacency list
Graph_Node* createNode(int dest, int weight) {
    Graph_Node* newNode = (Graph_Node*)malloc(sizeof(Graph_Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; ++i) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest, int weight) {
    Graph_Node* newNode = createNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Function to create a new min-heap node
MinHeapNode* createMinHeapNode(int vertex, int distance) {
    MinHeapNode* newNode = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    newNode->vertex = vertex;
    newNode->distance = distance;
    return newNode;
}

// Function to create a min-heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->pos = (int*)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->heap_capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc(capacity * sizeof(MinHeapNode*));
    return minHeap;
}

// Function to swap two min-heap nodes
void swapMinHeapNodes(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the min-heap
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->distance < minHeap->array[smallest]->distance) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->array[right]->distance < minHeap->array[smallest]->distance) {
        smallest = right;
    }

    if (smallest != idx) {
        MinHeapNode* smallestNode = minHeap->array[smallest];
        MinHeapNode* idxNode = minHeap->array[idx];

        minHeap->pos[smallestNode->vertex] = idx;
        minHeap->pos[idxNode->vertex] = smallest;

        swapMinHeapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Function to check if the min-heap is empty
bool isEmpty(MinHeap* minHeap) {
    return minHeap->size == 0;
}

// Function to extract the minimum node from the min-heap
MinHeapNode* extractMin(MinHeap* minHeap) {
    if (isEmpty(minHeap)) {
        return NULL;
    }

    MinHeapNode* rootNode = minHeap->array[0];
    MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];

    minHeap->array[0] = lastNode;

    minHeap->pos[rootNode->vertex] = minHeap->size - 1;
    minHeap->pos[lastNode->vertex] = 0;

    --minHeap->size;
    minHeapify(minHeap, 0);

    return rootNode;
}

// Function to decrease the distance value of a given vertex in the min-heap
void decreaseDistance(MinHeap* minHeap, int vertex, int distance) {
    int idx = minHeap->pos[vertex];
    minHeap->array[idx]->distance = distance;

    while (idx && minHeap->array[idx]->distance < minHeap->array[(idx - 1) / 2]->distance) {
        minHeap->pos[minHeap->array[idx]->vertex] = (idx - 1) / 2;
        minHeap->pos[minHeap->array[(idx - 1) / 2]->vertex] = idx;
        swapMinHeapNodes(&minHeap->array[idx], &minHeap->array[(idx - 1) / 2]);

        idx = (idx - 1) / 2;
    }
}

// Function to print the shortest path distances from the source vertex to all other vertices
void printShortestPathDistances(int* dist, int numVertices, int source) {
    FILE* outputFile = fopen("dijkstra.txt", "w");

    // Create an array to store the vertices in ascending order
    int vertices[MAX_VERTICES];
    for (int i = 0; i < numVertices; ++i) {
        vertices[i] = i;
    }

    // Sort the vertices array based on their distances
    for (int i = 0; i < numVertices - 1; ++i) {
        for (int j = 0; j < numVertices - i - 1; ++j) {
            if (dist[vertices[j]] > dist[vertices[j + 1]]) {
                int temp = vertices[j];
                vertices[j] = vertices[j + 1];
                vertices[j + 1] = temp;
            }
        }
    }

    // Print the shortest path distances in ascending order of vertices
    for (int i = 0; i < numVertices; ++i) {
        if (dist[vertices[i]] == INT_MAX) {
            fprintf(outputFile, "%d -1\n", vertices[i]);
        } else {
            fprintf(outputFile, "%d %d\n", vertices[i], dist[vertices[i]]);
        }
    }

    fclose(outputFile);
}

// Function to implement Dijkstra's algorithm
void dijkstra(Graph* graph, int source) {
    int numVertices = graph->numVertices;
    int dist[MAX_VERTICES];
    bool visited[MAX_VERTICES];

    MinHeap* minHeap = createMinHeap(numVertices);

    for (int v = 0; v < numVertices; ++v) {
        dist[v] = INT_MAX;
        visited[v] = false;
        minHeap->array[v] = createMinHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
    }

    minHeap->array[source] = createMinHeapNode(source, dist[source]);
    minHeap->pos[source] = source;
    dist[source] = 0;
    decreaseDistance(minHeap, source, dist[source]);

    minHeap->size = numVertices;

    while (!isEmpty(minHeap)) {
        MinHeapNode* minNode = extractMin(minHeap);
        int u = minNode->vertex;
        visited[u] = true;

        Graph_Node* temp = graph->array[u].head;
        while (temp != NULL) {
            int v = temp->dest;

            if (!visited[v] && dist[u] != INT_MAX && dist[u] + temp->weight < dist[v]) {
                dist[v] = dist[u] + temp->weight;
                decreaseDistance(minHeap, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    printShortestPathDistances(dist, numVertices, source);

    for (int i = 0; i < numVertices; ++i) {
        free(minHeap->array[i]);
    }

    free(minHeap->pos);
    free(minHeap->array);
    free(minHeap);
}

int main() {
    int numVertices, numEdges, source;
    scanf("%d %d %d", &numVertices, &numEdges, &source);

    Graph* graph = createGraph(numVertices);

    for (int i = 0; i < numEdges; ++i) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    dijkstra(graph, source);

    return 0;
}
