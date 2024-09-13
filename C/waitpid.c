#include<stdio.h>
#include<time.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int main(){
    int pid1 = fork();
    if( pid1 < 0){
        printf("Error in creating processes");
        return 1;
    }
    if( pid1 == 0){
        sleep(4);
        printf("Finished execution of (%d)\n", getpid());
        return 0;
    }

    int pid2 = fork();
    if( pid2 < 0){
        printf("Error in creating processes");
        return 1;
    }
    if( pid2 == 0){
        sleep(1);
        printf("Finished execution of (%d)\n", getpid());
        return 0;
    }

    int pid1_res = waitpid(pid1, NULL, 0);

    int pid2_res = waitpid(pid2, NULL, 0);
    return 0;
}