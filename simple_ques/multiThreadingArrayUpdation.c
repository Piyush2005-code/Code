#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

void *addressIncrement(void *arg) {
    int *a = (int *)arg;
    (*a)++;
    return NULL;
}

void printArr(int *arr, int n) {
    printf("Current state of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {

    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    pthread_t threadArr[n];

    clock_t start_time, end_time;
    double cpu_time_used;

    start_time = clock();

    for (int i = 0; i < n; i++) {
        if (pthread_create(&threadArr[i], NULL, addressIncrement, &arr[i]) != 0) {
            perror("pthread_create");
            return 1;
        }
    }

    for (int i = 0; i < n; i++) {
        pthread_join(threadArr[i], NULL);
    }

    end_time = clock();

    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("\nAfter Multithreaded Increment:\n");
    printArr(arr, n);

    printf("CPU time (Multithreaded): %f seconds\n", cpu_time_used);

    start_time = clock();

    for (int i = 0; i < n; i++) {
        arr[i]++;
    }

    end_time = clock();

    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("\nAfter Single-threaded Increment:\n");
    printArr(arr, n);

    printf("CPU time (Single-threaded): %f seconds\n", cpu_time_used);

    return 0;
}
