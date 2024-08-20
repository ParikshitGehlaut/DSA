#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    // struct stack *s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int*)malloc(s.size*sizeof(int));

    struct stack *s;
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // pushing an element manually
    // s->arr[0] = 7;
    // s->top++;
    // s->arr[0] = 8;
    // s->top++;
    // s->arr[0] = 9;
    // s->top++;
    // s->arr[0] = 10;
    // s->top++;
    // s->arr[0] = 11;
    // s->top++;

    // check if stack is empty
    if(isEmpty(s)){
        printf("The stack is empty");
    }else{
         printf("The stack is not empty\n");
    }
    // check is stack is full
    if(isFull(s)){
        printf("The stack is full");
    }else{
         printf("The stack is not full");
    }

    return 0;
}