#include<stdio.h>

int main() {
    int value = 10;
    int *ptr1 = &value;
    int **ptr2 = &ptr1;

    printf("Value: %d\n", value);
    printf("Value through ptr1: %d\n", *ptr1);
    printf("Value through ptr2: %d\n", **ptr2);
    printf("%d\n",ptr1);

    return 0;
}
