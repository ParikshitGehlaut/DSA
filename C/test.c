#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define Max_No_Vertex 2000

typedef struct iPair {
    int first;
    int second;
    struct iPair* next;
} iPair;

typedef struct {
    int V;
    iPair** adj;
} Graph;

Graph createGraph(int V) {
    Graph graph;
    graph.V = V;
    graph.adj = (iPair**)malloc(V * sizeof(iPair*));
    for (int i = 0; i < V; ++i)
        graph.adj[i] = NULL;
    return graph;
}

void addEdge(Graph* graph, int u, int v, int w) {
    iPair* newNode = (iPair*)malloc(sizeof(iPair));
    newNode->first = v;
    newNode->second = w;
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;

    newNode = (iPair*)malloc(sizeof(iPair));
    newNode->first = u;
    newNode->second = w;
    newNode->next = graph->adj[v];
    graph->adj[v] = newNode;
}

void shortestPath(Graph graph, int src) {
    int V = graph.V;
    iPair** adj = graph.adj;

    bool* visited = (bool*)malloc(V * sizeof(bool));
    int* dist = (int*)malloc(V * sizeof(int));

    for (int i = 0; i < V; ++i) {
        visited[i] = false;
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = -1;

        for (int i = 0; i < V; ++i) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }

        visited[u] = true;

        iPair* node = adj[u];
        while (node != NULL) {
            int v = node->first;
            int weight = node->second;

            if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;

            node = node->next;
        }
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);

    free(visited);
    free(dist);
}

int main(int argc, char* argv[]) {
    FILE *in ,*out;

    in = fopen(argv[1],"r");
    if(in==NULL){
        printf("Failed to open the input file.\n");
        return 1;
    }
    int V = Max_No_Vertex;
    int src = atoi(argv[2]);
    Graph graph = createGraph(V);

    // addEdge(&graph, 0, 1, 4);
    // addEdge(&graph, 0, 7, 8);
    // addEdge(&graph, 1, 2, 8);
    // addEdge(&graph, 1, 7, 11);
    // addEdge(&graph, 2, 3, 7);
    // addEdge(&graph, 2, 8, 2);
    // addEdge(&graph, 2, 5, 4);
    // addEdge(&graph, 3, 4, 9);
    // addEdge(&graph, 3, 5, 14);
    // addEdge(&graph, 4, 5, 10);
    // addEdge(&graph, 5, 6, 2);
    // addEdge(&graph, 6, 7, 1);
    // addEdge(&graph, 6, 8, 6);
    // addEdge(&graph, 7, 8, 7);
    int u, v, w;
    while (fscanf(in, "%d %d %d", &u, &v, &w) != EOF)
    {
        addEdge(&graph, u, v, w);
    }
    shortestPath(graph, src);

    for (int i = 0; i < V; ++i) {
        iPair* node = graph.adj[i];
        while (node != NULL) {
            iPair* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(graph.adj);

    return 0;
}
