#include<stdio.h>
#include<stdlib.h>

struct Graph_Node{
    int data;
    struct Graph_Node *next ;// self referencing structure
};

void linkedlistTransversal(struct Graph_Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element :%d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Graph_Node * insertionAtFirst(struct Graph_Node *head,int data){
    struct Graph_Node *ptr = (struct Graph_Node*)malloc(sizeof(struct Graph_Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
};

struct Graph_Node * insertionAtIndex(struct Graph_Node *head,int data,int index){
    struct Graph_Node *ptr = (struct Graph_Node*)malloc(sizeof(struct Graph_Node));
    ptr->data = data;
    struct Graph_Node *p = head;
    int i = 0;
    while(i != index-1){
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return ptr;
};

struct Graph_Node *insertionAtEnd(struct Graph_Node *head,int data){
    struct Graph_Node *ptr = (struct Graph_Node*)malloc(sizeof(struct Graph_Node));
    ptr->data = data;
    struct Graph_Node *p = head;
    while(p->next != NULL){
        p = p->next;
    }
    ptr->next = NULL;
    p->next = ptr;
    return head;

};


int main(){
    struct Graph_Node *head;
    struct Graph_Node *second;
    struct Graph_Node *third;
    struct Graph_Node *fourth;

    head = (struct Graph_Node*)malloc(sizeof(struct Graph_Node));
    second = (struct Graph_Node *)malloc(sizeof(struct Graph_Node));
    third = (struct Graph_Node *)malloc(sizeof(struct Graph_Node));
    fourth = (struct Graph_Node *)malloc(sizeof(struct Graph_Node));

    head->data = 7;
    head->next = second;

    // link second and third nodes
    second->data = 11;
    second->next = third;

     // link third and fourth nodes
    third->data = 27;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;

    linkedlistTransversal(head);
    // head = insertionAtFirst(head,56);
    // linkedlistTransversal(head);
    //insertionAtIndex(head,56,1);
    insertionAtEnd(head,56);
    linkedlistTransversal(head);
    return 0;
}