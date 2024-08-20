#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
creating a structure called node that contains data and address of next node
*/
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;
// enqueue function is used to enqueue elements from queue
void Enqueue(int e, FILE *out) {
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = e;
    n->next = NULL;
    if ((tail == NULL) && (head == NULL)) {
        head = tail = n;
        tail->next = head;
    } else {
        tail->next = n;
        tail = n;
        tail->next = head;
    }
    fprintf(out,"Inserted value: %d\n", e);
}
// dequeue function is used to dequeue elements from queue
void Dequeue(FILE *out) {
    struct node *k;
    k = head;
    if ((tail == NULL) && (head == NULL)) {
        fprintf(out,"Queue is empty\n");
    } else if (head == tail) {
        head = tail = NULL;
        fprintf(out,"deleted value: %d\n", k->data);
        free(k);
    } else {
        head = head->next;
        tail->next = head;
        fprintf(out,"deleted value: %d\n", k->data);
        free(k);
    }
}
/*
this function is used to display queue and its elements
*/
void Display(FILE *out) {
    struct node *k;
    k = head;
    if ((tail == NULL) && (head == NULL)) {
        fprintf(out, "Queue is empty");
    } else {
        fprintf(out, "Elements of the queue:");
        do {
            fprintf(out, " %d", k->data);
            k = k->next;
        } while (k != head);
    }
    fprintf(out, "\n");
}

int main(int argc , char* argv[]) {
    FILE *in, *out;
    char command[10];
    int e;
    // openning the input file
    in = fopen(argv[1], "r");
    if(in == NULL){
        printf("Error in openning input file");
    }
    // openning the output file
    out = fopen("output.txt", "w");
     if(out == NULL){
        printf("Error in openning output file");
    }

    while (fscanf(in, "%s", command) != EOF) {
        if (strcmp(command, "enqueue") == 0) {
            fscanf(in, "%d", &e);
            Enqueue(e,out);
        } else if (strcmp(command, "dequeue") == 0) {
            Dequeue(out);
        } else if (strcmp(command, "display") == 0) {
            Display(out);
        }
    }

    // closing the input and output file
    fclose(in);
    fclose(out);

    return 0;
}
