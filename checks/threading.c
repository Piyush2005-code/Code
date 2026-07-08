#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>


void* func(void* arg){
    int i = 1;
    while(1){
        printf("the tick of the clock now %d\n", i);
        sleep(1);
        i++;
    }
    return NULL;
}

int main(){

    pthread_t thread;
    // When this thread is created, this executes parallel to the main thread...
    pthread_create(&thread, NULL, func, NULL);
    // In the main thread sleep(5) executes, and parallely func() is executed throughout with its sleep(1) in every one second so while that time sleep(5) executes the completion.
    sleep(5);

    pthread_cancel(thread);

}