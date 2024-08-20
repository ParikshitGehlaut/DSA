#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int d) {
    struct node *newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = d;
    newnode->next = NULL;
    if ((rear == NULL) && (front == NULL)) {
        front = rear = newnode;
        rear->next = front;
    } else {
        rear->next = newnode;
        rear = newnode;
        newnode->next = front;
    }
}

void dequeue(FILE *fp2) {
    int x;
    if (front == NULL) {
        fprintf(fp2, "Queue is Empty\n");
    } else if (front == rear) {
        x = front->data;
        fprintf(fp2, "deleted value: %d\n", x);
        free(front);
        rear = front = NULL;
    } else {
        struct node *temp;
        temp = front;
        x = front->data;
        fprintf(fp2, "deleted value: %d\n", x);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display(FILE *fp2) {
    struct node *t;
    t = front;
    if ((front == NULL) && (rear == NULL)) {
        fprintf(fp2, "Queue is Empty\n");
    } else {
        fprintf(fp2, "Elements of the queue: ");
        fprintf(fp2, " %d", t->data);
        t = t->next;

        while (t != front) {
            fprintf(fp2, " %d", t->data);
            t = t->next;
        }
        fprintf(fp2, "\n");
    }
}

int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int main(int argc, char *argv[]) {
    FILE *fp1, *fp2;
    char str[100];
    fp1 = fopen(argv[1], "r");
    fp2 = fopen("output.txt", "w");

    while (fgets(str, 60, fp1) != NULL) {
        if (str[0] == 'e' && str[8] != '-') {
            int j = strlen(str) - 10;
            int n = 0;
            for (int i = 8; i < strlen(str) - 1; i++) {
                n = n + ((int) str[i] - 48) * power(10, j);
                j--;
            }
            enqueue(n);
            fprintf(fp2, "Inserted value: %d\n", n);
        } else if (str[0] == 'd' && str[1] == 'i') {
            display(fp2);
        } else if (str[0] == 'e' && str[8] == '-') {
            int j = strlen(str) - 11, n = 0;
            for (int i = 9; i < strlen(str) - 1; i++) {
                n = n + ((int) str[i] - 48) * power(10, j);
                j--;
            }
            enqueue(-1 * n);
            fprintf(fp2, "Inserted value: %d\n", -1 * n);
        } else if (str[0] == 'd' && str[1] == 'e') {
            dequeue(fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
}
