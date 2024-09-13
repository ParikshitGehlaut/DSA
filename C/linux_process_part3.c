#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int main(){
    int id = fork();
    int n;

    if(id == 0){
        n = 1;
    }else{
        n = 6;
    }

    if( id != 0){
        wait();
    }

    for(int i=n; i < n+5; i++){
        printf("%d\n", i);
        fflush(stdout);
    }
    return 0;
}