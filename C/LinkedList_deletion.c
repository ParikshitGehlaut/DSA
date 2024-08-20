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
// case - 1 
struct Graph_Node * deletionAtFirst(struct Graph_Node* head){
    struct Graph_Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
// case - 2
struct Graph_Node * deletionAtIndex(struct Graph_Node* head, int idx){
    struct Graph_Node* p = head;
    struct Graph_Node* q = head->next;
    int i = 0;
    for(i=0;i< idx-1;i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Graph_Node * deletionAtEnd(struct Graph_Node* head){
    struct Graph_Node* p = head;
    struct Graph_Node* q = head->next;
    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    free(q);
    p->next = NULL;
    return head;
}

int main()
{
    struct Graph_Node *head;
    struct Graph_Node *second;
    struct Graph_Node *third;
    struct Graph_Node *fourth;

    // allocate memory for nodes in the linked list in heap
    head = (struct Graph_Node *)malloc(sizeof(struct Graph_Node));
    second = (struct Graph_Node *)malloc(sizeof(struct Graph_Node));
    third = (struct Graph_Node *)malloc(sizeof(struct Graph_Node));
    fourth = (struct Graph_Node *)malloc(sizeof(struct Graph_Node));

    head->data = 7;
    head->next = second;

    // link second and third nodes
    second->data = 11;
    second->next = third;

    //link third and fourth nodes
    third->data = 66;
    third->next = fourth;

    //link fourth and third nodes
    fourth->data = 27;
    fourth->next = NULL;

    linkedlistTransversal(head);
    head = deletionAtEnd(head);
    printf("linked list after deletion\n");
    linkedlistTransversal(head);
    return 0;
}