#include<stdio.h>
#include<stdlib.h>

struct Graph_Node{
    int data;
    struct Graph_Node *next;
};

void circularlinkedlist(struct Graph_Node *head){
    struct Graph_Node *p = head;
    do{
        printf("Element :%d\n",p->data);
        p = p->next;
    }while(p != head);
}

struct Graph_Node *insertionAtFirst(struct Graph_Node *head, int data){
    struct Graph_Node *ptr = (struct Graph_Node*)malloc(sizeof(struct Graph_Node));
    ptr->data = data;
    
    struct Graph_Node *p = head->next;
    while(p->next != head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
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
    fourth->next = head;

    circularlinkedlist(head);
    head = insertionAtFirst(head,80);
    // for(int i=0;i<=5;i++){
    //     head = insertionAtFirst(head,i);
    // }
    printf("Linked list after insertion:\n");
    circularlinkedlist(head);
    return 0;
}