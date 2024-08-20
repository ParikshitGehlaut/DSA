#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 1000

typedef struct iPair
{
    int first;
    int second;
    struct iPair *next;
} iPair;

typedef struct
{
    int V;
    iPair **adj;
} Graph;

Graph createGraph(int V)
{
    Graph graph;
    graph.V = V;
    graph.adj = (iPair **)malloc(V * sizeof(iPair *));
    for (int i = 0; i < V; ++i)
        graph.adj[i] = NULL;
    return graph;
}

void addEdge(Graph *graph, int u, int v, int w)
{
    iPair *newNode = (iPair *)malloc(sizeof(iPair));
    newNode->first = v;
    newNode->second = w;
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;

    newNode = (iPair *)malloc(sizeof(iPair));
    newNode->first = u;
    newNode->second = w;
    newNode->next = graph->adj[v];
    graph->adj[v] = newNode;
}

void shortestPath(Graph graph, int src, FILE *out)
{
    int V = graph.V;
    iPair **adj = graph.adj;

    bool *visited = (bool *)malloc(V * sizeof(bool));
    int *dist = (int *)malloc(V * sizeof(int));

    for (int i = 0; i < V; ++i)
    {
        visited[i] = false;
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; ++count)
    {
        int u = -1;

        for (int i = 0; i < V; ++i)
        {
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }

        visited[u] = true;

        iPair *node = adj[u];
        while (node != NULL)
        {
            int v = node->first;
            int weight = node->second;

            if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;

            node = node->next;
        }
    }

    for (int i = 0; i < V; ++i)
    {
        if (dist[i] != INT_MAX)
        {
            fprintf(out, "%d %d\n", i, dist[i]);
        }
        else
        {
            fprintf(out, "%d %d\n", i, -1);
        }
    }

    free(visited);
    free(dist);
}

int isRepeated(int arr[], int size, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    FILE *in = NULL, *out = NULL;

    if (argc < 3)
    {
        printf("Usage: %s input_file source_vertex\n", argv[0]);
        return 1;
    }

    in = fopen(argv[1], "r");
    if (in == NULL)
    {
        printf("Failed to open the input file.\n");
        return 1;
    }

    int numbers[MAX_SIZE];
    int count = 0;
    int num1, num2, num3;
    while (fscanf(in, "%d %d %d", &num1, &num2, &num3) != EOF)
    {
        if (!isRepeated(numbers, count, num1))
        {
            numbers[count] = num1;
            count++;
        }
        if (!isRepeated(numbers, count, num2))
        {
            numbers[count] = num2;
            count++;
        }
    }

    int V = count;
    int src = atoi(argv[2]);
    Graph graph = createGraph(V);

    rewind(in); // Reset the file pointer to the beginning

    int u, v, w;
    while (fscanf(in, "%d %d %d", &u, &v, &w) != EOF)
    {
        addEdge(&graph, u, v, w);
    }

    fclose(in);

    out = fopen("dijkstra.txt", "w");
    if (out == NULL)
    {
        printf("Failed to open output file.\n");
        return 1;
    }

    shortestPath(graph, src, out);

    for (int i = 0; i < V; ++i)
    {
        iPair *node = graph.adj[i];
        while (node != NULL)
        {
            iPair *temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(graph.adj);

    fclose(out);

    return 0;
}
