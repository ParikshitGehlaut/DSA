#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front_node, back_node, size;
    int* array;
};

int isQueueEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

int isQueueFull(struct Queue* queue) {
    return (queue->back_node == queue->size - 1);
}


void enqueue(struct Queue* queue, int item) {
    if (isQueueFull(queue)) {
        printf("This queue is full\n");
    } else {
        queue->array[queue->back_node] = item;
        queue->back_node++;
        queue->size++;
    }
}

int dequeue(struct Queue* queue) {
    int item = -1;
    if (isQueueEmpty(queue)) {
        printf("The queue is empty\n");
    } else {
        item = queue->array[queue->front_node];
        queue->front_node++;
        queue->size--;
    }
    return item;
}

int main(int argc, char* argv[]) {
    FILE* in, *out;
    in = fopen(argv[1], "r");
    if (in == NULL) {
        printf("There is an error opening the input file.\n");
        return 1;
    }
    out = fopen("sd.txt", "w");
    if (out == NULL) {
        printf("There is an error opening the output file.\n");
        return 1;
    }

    int vertex, edge;
    fscanf(in, "%d %d", &vertex, &edge);

    // Creating Queue for BFS implementation
    struct Queue* queue;
    queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front_node = queue->back_node = queue->size = 0;
    queue->array = (int*)malloc((vertex + 1) * sizeof(int));

    // BFS implementation
    int node;
    int* visited = (int*)malloc(vertex * sizeof(int));
    int* distance = (int*)malloc(vertex * sizeof(int));
    for (int k = 0; k < vertex; k++) {
        visited[k] = 0;
        distance[k] = -1;
    }

    // Using Adjacency Matrix
    int** adj = (int**)malloc(vertex * sizeof(int*));
    for (int x = 0; x < vertex; x++) {
        adj[x] = (int*)malloc(vertex * sizeof(int));
        for (int y = 0; y < vertex; y++) {
            adj[x][y] = 0;
        }
    }

    int a, b;
    while (fscanf(in, "%d %d", &a, &b) == 2) {
        adj[a][b] = adj[b][a] = 1;
    }

    visited[0] = 1;
    distance[0] = 0; // distance of vertex from itself is zero
    enqueue(queue, 0); // enqueue 0 for exploration
    while (!isQueueEmpty(queue)) {
        node = dequeue(queue);
        for (int z = 1; z < vertex; z++) {
            if (adj[node][z] == 1 && visited[z] == 0) {
                visited[z] = 1;
                distance[z] = distance[node] + 1;
                enqueue(queue, z);
            }
        }
    }

    // Print the shortest distance from the source vertex to each vertex
    for (int k = 0; k < vertex; k++) {
        fprintf(out, "%d\n", distance[k]);
    }

    // Clean up allocated memory
    fclose(in);
    fclose(out);
    free(queue->array);
    free(queue);
    free(visited);
    free(distance);
    for (int x = 0; x < vertex; x++) {
        free(adj[x]);
    }
    free(adj);

    return 0;
}
