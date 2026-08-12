#include<stdio.h>
#include<unistd.h>



// The simplest piece of program for the fork function:
int main(){
    pid_t pid1 = fork();
    pid_t pid2 = fork();
    printf("Hello %d, %d\n", pid1, pid2);
}
