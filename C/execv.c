#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>
int main() {
    printf("Before execv\n");
    char *args[] = { "pwd", NULL };
    int pid = fork();
    if(pid == 0){
        execv("/bin/pwd", args);
        perror("execv failed");
    }else{
        waitpid(pid, NULL, 0);
        printf("I am parent of child process (%d)\n", pid);
    }
    
    return 0;
}
