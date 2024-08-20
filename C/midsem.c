#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

struct Graph_Node{
    int data;
    struct Graph_Node *prev;
    struct Graph_Node *next;
};

struct node *top = NULL;
int count = 0;
struct node *f = NULL;
struct node *r = NULL;
int var = 0;

struct Graph_Node *head = NULL;


struct Graph_Node* createNode(int data) {
    struct Graph_Node* newNode = (struct Graph_Node*)malloc(sizeof(struct Graph_Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insert(int data, FILE* out3) {
    struct Graph_Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Graph_Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    fprintf(out3, "inserted %d\n", data);
}

void deleteNode(int data, FILE* out3) {
    if (head == NULL) {
        fprintf(out3, "underflow\n");
        return;
    }

    struct Graph_Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    while (current != NULL) {
        if (current->data == data) {
            if (current == head) {
                head = current->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            } else {
                current->prev->next = current->next;
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
            }
            free(current);
            fprintf(out3, "deleted %d\n", data);
            return;
        }
        current = current->prev;
    }

    fprintf(out3, "cannot delete %d\n", data);
}


void traversal(FILE* out3) {
    if (head == NULL) {
        fprintf(out3, "\n");
        return;
    }

    struct Graph_Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    while (current != NULL) {
        fprintf(out3, "%d ", current->data);
        current = current->prev;
    }
    fprintf(out3, "\n");
}


struct Graph_Node* searchinDll(int data, FILE* out3) {
    struct Graph_Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int isEmpty()
{
    return (top == NULL);
}

int isFull(int size)
{
    return (count == size);
}

struct node *push(int a, FILE *out1, int size)
{
    if (isFull(size))
    {
        fprintf(out1, "overflow\n");
    }
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = a;
        n->next = top;
        top = n;
        fprintf(out1, "pushed %d\n", a);
        count++;
    }
    return top;
}

struct node *pop(FILE *out1, int a)
{
    if (isEmpty())
    {
        fprintf(out1, "underflow\n");
    }
    else
    {
        struct node *n = top;
        top = n->next;
        fprintf(out1, "popped %d\n", n->data);
        free(n);
        count--;
    }
    return top;
}

void stackTraversal(FILE *out1)
{
    struct node *p = top;
    while (p != NULL)
    {
        fprintf(out1, "%d ", p->data);
        p = p->next;
    }
}

struct node *search(FILE *out1, int a)
{
    struct node *current = top;
    while (current != NULL)
    {
        if (current->data == a)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

struct node *searchinQueue(FILE *out2, int a) {
    if (f == NULL) {
        return NULL;
    }

    struct node *current = f;
    do {
        if (current->data == a) {
            return current;
        }
        current = current->next;
    } while (current != f);

    return NULL;
}

// enqueue function is used to enqueue elements from queue
void Enqueue(int e, FILE *out2, int size) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = e;
    n->next = NULL;

    if (var == size) {
        fprintf(out2, "overflow\n");
    } else {
        var++;
        if (f == NULL) {
            f = r = n;
            r->next = f;  // Set the next pointer of the rear node to the front node
        } else {
            r->next = n;
            r = n;
            r->next = f;  // Set the next pointer of the rear node to the front node
        }
        fprintf(out2, "enqueued %d\n", e);
    }
}


// dequeue function is used to dequeue elements from queue
void Dequeue(FILE *out2) {
    int temp;
    struct node *ptr = f;
    if (f == NULL) {
        fprintf(out2, "underflow\n");
    } else {
        var--;
        f = f->next;
        temp = ptr->data;
        free(ptr);

        if (var == 0) {
            f = r = NULL;  // Reset front and rear pointers when the queue becomes empty
        } else {
            r->next = f;  // Set the next pointer of the rear node to the front node
        }
        fprintf(out2, "dequeued %d\n", temp);
    }
}

// this function is used to display queue and its elements
void Display(FILE *out2) {
    if (f == NULL) {
        fprintf(out2, "\n");
        return;
    }

    struct node *p = f;
    do {
        fprintf(out2, "%d ", p->data);
        p = p->next;
    } while (p != f);

    fprintf(out2, "\n");
}


int main(int argc, char *argv[])
{
    FILE *in, *out1, *out2, *out3;
    int Size = atoi(argv[2]);

    in = fopen(argv[1], "r");
    if (in == NULL)
    {
        fprintf(out1,"Error in opening input file\n");
        fprintf(out2,"Error in opening input file\n");
        fprintf(out3,"Error in opening input file\n");
        return 1;
    }

    out1 = fopen("stack.txt", "w");
    if (out1 == NULL)
    {
        printf("Error in opening stack.txt\n");
        fclose(in);
        return 1;
    }

    out2 = fopen("queue.txt", "w");
    if (out2 == NULL)
    {
        printf("Error in opening queue.txt\n");
        fclose(in);
        fclose(out1);
        return 1;
    }

    out3 = fopen("dll.txt", "w");
    if (out3 == NULL)
    {
        printf("Error in opening dll.txt\n");
        fclose(in);
        fclose(out1);
        fclose(out2);
        return 1;
    }

    char command[100];
    int a;
    while (fscanf(in, "%s", command) != EOF)
    {
        if (strcmp(command, "+") == 0)
        {
            fscanf(in, "%d", &a);
            top = push(a, out1, Size);
            Enqueue(a, out2, Size);
            insert(a, out3);
        }
        else if (strcmp(command, "-") == 0)
        {
            fscanf(in, "%d", &a);
            top = pop(out1, a);
            Dequeue(out2);
            deleteNode(a,out3);
        }
        else if (strcmp(command, "!") == 0)
        {
            stackTraversal(out1);
            Display(out2);
            fprintf(out1, "\n");
            traversal(out3);
        }
        else if (strcmp(command, "?") == 0)
        {
            fscanf(in, "%d", &a);
            struct node *result = search(out1,a);
            if (result != NULL)
            {
                fprintf(out1, "found %d\n", a);
            }
            else
            {
                fprintf(out1, "not found %d\n", a);
            }
            struct node *result2 = searchinQueue(out2, a);
            if (result2 != NULL)
            {
                fprintf(out2, "found %d\n", a);
            }
            else
            {
                fprintf(out2, "not found %d\n", a);
            }
            struct Graph_Node *foundNode = searchinDll(a,out3);
            if (foundNode != NULL)
            {
                fprintf(out3,"found %d\n", a);
            }
            else
            {
                fprintf(out3,"not found %d\n", a);
            }
        }
    }

    fclose(in);
    fclose(out1);
    fclose(out2);
    fclose(out3);

    return 0;
}
