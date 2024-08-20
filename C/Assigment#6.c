#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct queue* q) {
    if (q->f == q->r) {
        return 1;
    }
    return 0;
}

int isFull(struct queue* q) {
    if ((q->r + 1) % q->size == q->f) {
        return 1;
    }
    return 0;
}

int enqueue(struct queue* q, int val) {
    if (isFull(q)) {
        printf("This queue is full\n");
        return -1;
    }
    else {
        q->r = (q->r + 1) % q->size;  // circular iteration
        q->arr[q->r] = val;
        return 0;
    }
}

int dequeue(struct queue* q) {
    int a = -1;
    if (isEmpty(q)) {
        printf("The queue is empty\n");
        return -1;
    }
    else {
        a = q->arr[q->f];
        q->f = (q->f + 1) % q->size;
        return a;
    }
}

int main(int argc, char* argv[]) {
    FILE* in, * out;
    in = fopen(argv[1], "r");
    if (in == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    out = fopen("sd.txt", "w");
    if (out == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    int vertex, edge;
    fscanf(in, "%d %d", &vertex, &edge);

    // Creating Queue for BFS implementation
    struct queue* q;
    q = (struct queue*)malloc(sizeof(struct queue));
    q->size = vertex + 1;
    q->f = q->r = 0;
    q->arr = (int*)malloc(q->size * sizeof(int));

    // BFS implementation
    int node;
    int visited[q->size];
    int distance[q->size];
    int i = 0;
    for (int k = 0; k < q->size - 1; k++) {
        visited[k] = 0;
        distance[k] = -1;
    }
    // Using Auxiliary Matrix
    int aux[q->size][q->size];
    for (int i = 0; i < q->size; i++) {
        for (int j = 0; j < q->size; j++) {
            aux[i][j] = 0;
        }
    }
    int a, b;
    while (fscanf(in, "%d %d", &a, &b) == 2) {
        aux[a][b] = aux[b][a]= 1;
    }
    

    visited[i] = 1;
    distance[i] = 0; // distance of vertex from itself is zero
    enqueue(q, i);  // enqueue i for exploration
    while (!isEmpty(q)) {
        int node = dequeue(q);
        for (int j = 0; j < q->size; j++) {
            if (aux[node][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                distance[j] = distance[node] + 1; // Update the distance of the adjacent vertex
                enqueue(q, j);
            }
        }
    }

    // Print the shortest distance from the source vertex to each vertex
    for (int k = 0; k < q->size - 1; k++) {
        fprintf(out, "%d\n", distance[k]);
    }

    // Closing input and output file
    fclose(in);
    fclose(out);

    return 0;
}
