#include <stdio.h>
#include <pthread.h>
#include <time.h>

typedef struct
{
    int *arr;
    int start;
    int end;
} ThreadData;

void *addressIncrement(void *arg)
{
    ThreadData *data = (ThreadData *)arg;

    for(int i = data->start; i < data->end; i++)
    {
        data->arr[i]++;
    }

    return NULL;
}

void printArr(int *arr, int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    printf("\n");
}

int main()
{
    int n;

    printf("Enter array size : ");
    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++)
        arr[i]=i;

    int m;

    printf("Enter number of threads : ");
    scanf("%d",&m);

    pthread_t threads[m];
    ThreadData data[m];

    int chunk = n / m;
    int rem = n % m;

    clock_t start = clock();

    int current = 0;

    for(int i=0;i<m;i++)
    {
        data[i].arr = arr;

        data[i].start = current;

        data[i].end = current + chunk;

        if(i == m-1)
            data[i].end += rem;

        current = data[i].end;

        pthread_create(&threads[i],
                       NULL,
                       addressIncrement,
                       &data[i]);
    }

    for(int i=0;i<m;i++)
        pthread_join(threads[i],NULL);

    clock_t end = clock();

    printf("\nAfter Multithreaded Increment\n");
    // printArr(arr,n);

    printf("CPU Time = %f sec\n",
           (double)(end-start)/CLOCKS_PER_SEC);

    start = clock();

    for(int i=0;i<n;i++)
        arr[i]++;

    end = clock();

    printf("\nAfter Single-threaded Increment\n");
    // printArr(arr,n);

    printf("CPU Time = %f sec\n",
           (double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}
