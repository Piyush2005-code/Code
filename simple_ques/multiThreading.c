#include<stdio.h>
#include<assert.h>
#include<pthread.h>

// Now since this particular variable is a global variable, so the memory of the variable is shared between both the threads that are going to be run...
int counter = 0;

// Here since the function is basically increamenting the value of counter(global variable), so the two different threads eventually end up in a same variable update, which results in a race condition.
void *myThread(void *str){
    printf("\nStarting the execution of %s\n", (char *) str);
    for(int i = 0; i < 1e7; i++){
        counter = counter + 1;
    }
    printf("\nCompleting the execution of thread %s\n", (char *) str);
    return NULL;
}

// In this particular example, a race condition is created here as the MacOS is parallelising the execution of the two threads between two different cores.
int main(){

    pthread_t p1, p2;
    int rc;
    printf("\nThe test begins : \n");
    // Thread creation and execution starts.
    rc = pthread_create(&p1, NULL, myThread, "A"); assert (rc == 0);  
    rc = pthread_create(&p2, NULL, myThread, "B"); assert (rc == 0);
    
    // Now I will basically wait for the threads to complete their execution.
    rc = pthread_join(p1, NULL); assert (rc == 0);
    rc = pthread_join(p2, NULL); assert (rc == 0);
    
    printf("\nThe execution of the two threads have completed and the value of the global variable counter = %d after the execution of two different threads concurrently(might be wrong terminalogy here because I am just learning about concurrency and parallelism)\n", counter);
    
}
