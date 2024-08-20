#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

int minDistance(int dist[], bool arr[], int V)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
    {
        if (arr[v] == false && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// function to print the distance 
void printSolution(int* dist, int V, FILE *out)
{
    for (int i = 0; i < V; i++)
    {   if(dist[i] != INT_MAX){
            fprintf(out, "%d %d\n", i, dist[i]);
        }
        else{
            fprintf(out, "%d %d\n", i,-1);
        }
    }
}

// Dijkstra's algorithm implementation using adjacency matrix representation
void dijkstra(int **graph, int src, int V, FILE *out)
{
    int dist[V];    
    bool arr[V]; 

    // Initialize all distances as INFINITE and arr[] as false
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        arr[i] = false;
    }
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int k = 0; k < V - 1; k++)
    {
        int u = minDistance(dist, arr, V);
        arr[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!arr[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist, V, out);
}

int main(int argc, char *argv[])
{
    FILE *in = NULL, *out = NULL;

    if (argc <= 2)
    {
        printf("Error in command line");
        return 1;
    }

    in = fopen(argv[1], "r");
    if (in == NULL)
    {
        printf("Failed to open the input file.\n");
        return 1;
    }

    out = fopen("dijkstra.txt", "w");
    if (out == NULL)
    {
        printf("Failed to open the output file.\n");
        return 1;
    }

    int numVertices = 0;
    int x, y, w;
    while (fscanf(in, "%d %d %d", &x, &y, &w) != EOF)
    {
        if (x > numVertices)
            numVertices = x;
        if (y > numVertices)
            numVertices = y;
    }
    numVertices++;

    // create adjacency matrix dynamically based on the number of vertices
    int **graph = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++)
    {
        graph[i] = (int *)malloc(numVertices * sizeof(int));
        memset(graph[i], 0, numVertices * sizeof(int)); 
    }
    fseek(in, 0, SEEK_SET);
    int num1, num2, num3;
    while (fscanf(in, "%d %d %d", &num1, &num2, &num3) != EOF)
    {
        int vertex1 = num1;
        int vertex2 = num2;

        graph[vertex1][vertex2] = num3;
    }

    fclose(in);

    int source = atoi(argv[2]); 
    printf("%d\n",graph[22][3]);

    dijkstra(graph, source, numVertices, out); 

    for (int i = 0; i < numVertices; i++)
    {
        free(graph[i]);
    }
    free(graph);

    fclose(out);

    return 0;
}
