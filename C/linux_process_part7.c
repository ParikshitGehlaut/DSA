#include<stdio.h>
#include<unistd.h>

int main(){
    char *command = "/bin/ping";
    char *args[] = {"ping", "-c", "4", "google.com", NULL};

    if (execv(command, args) == -1) {
        perror("execv failed");
        return 1;
    }
    
    return 0;
}