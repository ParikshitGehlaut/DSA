#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    fork();
    fork();
    fork();
    fork();
    printf("Hello, World\n"); // this line will be printed 16 times
    return 0;
}