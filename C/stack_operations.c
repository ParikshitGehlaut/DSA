#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;

};
int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        printf("Stack overflow");
        return 1;
    }else{
        return 0;
    }

}

int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        //printf("Stack underflow\n");
        return 1;
    }else{
        return 0;
    }

}

void Push(struct stack *ptr, int val){
    if(isFull(ptr)){
        printf("Stack overflow");
    }else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }

}

int main(){
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int*)malloc(sp->size*sizeof(int)); 
   
   //printf("%d\n",isFull(sp));
   printf("%d\n",isEmpty(sp));
   Push(sp,56);
   printf("%d\n",isEmpty(sp));
    return 0;
}