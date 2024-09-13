#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int id = fork();

    if(id == 0){
        printf("Hello, I'm child process\n");
    }else{
        printf("Hello, I'm parent process of child %d\n", id);
    }
    return 0;
}