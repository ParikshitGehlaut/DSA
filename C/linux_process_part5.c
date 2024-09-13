#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int id = fork();
    if( id == 0 ){
        sleep(1); 
    }
    if( id == 0 ){
        printf("Id of child process is: %d, Id of parent is : %d\n", getpid(), getppid());
    }else{
        printf("Id of parent process is: %d, Id of its parent is : %d\n", getpid(), getppid());
    }

    if( id != 0 ){
        wait(NULL);
    }

    return 0;
}