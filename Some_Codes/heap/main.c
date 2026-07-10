#include<stdio.h>
#include<stdlib.h>
#include "heap.h"


int main(){

    int n; 
    printf("\nEnter the capacity of heap : ");
    scanf("%d", &n);

    struct Heap *h = initHeap(n);

    int x;

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        insertKey(h, x);
    }

    printf("\nThe state of the heap after inserting %d elements\n", n);
    printHeap(h);

    printf("\nEnter the number of elements to be removed from the top of heap : ");
    scanf("%d", &n);
    int t;

    for(int i = 0; i < n; i++){
        t = extractTop(h);
        printf("The extracted element from the top of the heap is : %d", t);
        printHeap(h);
    }
}
