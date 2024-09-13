#include<stdio.h>
#include<unistd.h>


int main(){
    printf("Before execvp\n");
    char *args[] = {"ps", "-ef", NULL};
    execvp("ps", args);
    perror("execvp failed");
    return 0;
}