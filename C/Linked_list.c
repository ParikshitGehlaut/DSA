#include <stdio.h>
#include <stdlib.h>

struct Graph_Node
{
    int data;
    struct Graph_Node *next;
};

void linkedlistTransversal(struct Graph_Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element :%d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct Graph_Node *head;
    struct Graph_Node *second;
    struct Graph_Node *third;

    // allocate memory for nodes in the linked list in heap
    head = (struct Graph_Node *)malloc(sizeof(struct Graph_Node));
    second = (struct Graph_Node *)malloc(sizeof(struct Graph_Node));
    third = (struct Graph_Node *)malloc(sizeof(struct Graph_Node));

    head->data = 7;
    head->next = second;

    // link second and third nodes
    second->data = 11;
    second->next = third;

    // Terminate the list at the third node
    third->data = 66;
    third->next = NULL;

    linkedlistTransversal(head);
    return 0;
}