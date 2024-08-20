#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

struct stack
{
    struct node *top;
    int count;
};

int isStackEmpty(struct stack *s)
{
    return (s->top == NULL);
}

int isStackFull(struct stack *s, int size)
{
    return (s->count == size);
}

struct node *push(struct stack *s, int a, FILE *fp, int size)
{
    if (isStackFull(s, size))
    {
        fprintf(fp, "overflow\n");
    }
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = a;
        n->next = s->top;
        s->top = n;
        fprintf(fp, "pushed %d\n", a);
        s->count++;
    }
    return s->top;
}

struct node *pop(struct stack *s, FILE *fp, int a)
{
    if (isStackEmpty(s))
    {
        fprintf(fp, "underflow\n");
    }
    else
    {
        struct node *p = s->top;
        s->top = p->next;
        fprintf(fp, "popped %d\n", p->data);
        free(p);
        s->count--;
    }
    return s->top;
}

void Display(struct stack *s, FILE *fp)
{
    struct node *p = s->top;
    while (p != NULL)
    {
        fprintf(fp, "%d ", p->data);
        p = p->next;
    }
}

struct node *search(struct stack *s, FILE *fp, int a)
{
    struct node *current = s->top;
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

int main(int argc, char *argv[])
{
    FILE *in, *fp;
    int Size = atoi(argv[2]);

    in = fopen(argv[1], "r");
    if (in == NULL)
    {
        printf("Error in opening input file\n");
        return 1;
    }

    fp = fopen("stack.txt", "w");
    if (fp == NULL)
    {
        printf("Error in opening stack.txt\n");
        return 1;
    }

    struct stack stk;
    stk.top = NULL;
    stk.count = 0;

    char function[500];
    int a;
    while (fscanf(in, "%s", function) != EOF)
    {
        if (strcmp(function, "+") == 0)
        {
            fscanf(in, "%d", &a);
            stk.top = push(&stk, a, fp, Size);
        }
        else if (strcmp(function, "-") == 0)
        {
            fscanf(in, "%d", &a);
            stk.top = pop(&stk, fp, a);
        }
        else if (strcmp(function, "!") == 0)
        {
            Display(&stk, fp);
            fprintf(fp, "\n");
        }
        else if (strcmp(function, "?") == 0)
        {
            fscanf(in, "%d", &a);
            struct node *Nnode = search(&stk, fp, a);
            if (Nnode != NULL)
            {
                fprintf(fp, "found %d\n", a);
            }
            else
            {
                fprintf(fp, "not found %d\n", a);
            }
        }
    }
    fclose(in);
    fclose(fp);
    return 0;
}
