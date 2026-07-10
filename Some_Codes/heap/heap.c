#include<stdio.h>
#include<stdlib.h>
#include "heap.h"


struct Heap* initHeap(int capacity){
    struct Heap* h = (struct Heap*)malloc(sizeof(struct Heap));
    h->arr = (int*)malloc(sizeof(int) * capacity);
    h->capacity = capacity;
    h->size = 0;
    return h;
}


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int getParent(int curr){
    return (curr - 1) / 2;
}


int getRightChild(int curr){
    return 2 * curr + 2;
}


int getLeftChild(int curr){
    return 2 * curr + 1;
}


void Heapify(struct Heap *heap, int i){
    int right = getRightChild(i);
    int left = getLeftChild(i);
    int priority = i;

    if(left < heap->size && heap->arr[left] < heap->arr[priority]){
        priority = left;
    }
    if(right < heap->size && heap->arr[right] < heap->arr[priority]){
        priority = right;
    }
    if(priority != i){
        swap(&heap->arr[i], &heap->arr[priority]);
        Heapify(heap, priority);
    }
}


void insertKey(struct Heap *heap, int key){
    if(heap->size == heap->capacity){
        printf("\nThe heap is already full...insert failed.");   
    }
    else if (heap->size < heap->capacity){
        heap->size++;
        heap->arr[heap->size - 1] = key;
        int i = heap->size - 1;
        while(i != 0 && heap->arr[i] < heap->arr[getParent(i)]){
            swap(&heap->arr[i], &heap->arr[getParent(i)]);
            i = getParent(i);
        }
    }
}


int top(struct Heap *heap){
    return heap->arr[0];
}


void printHeap(struct Heap* heap){
    printf("\n------ The current State of the Heap is ------\n");
    for(int i = 0; i < heap->size; i++){
        if(i == heap->size - 1) printf("%d", heap->arr[i]);
        else printf("%d, ", heap->arr[i]);
    }
    printf("\n");
}


int extractTop(struct Heap *heap){
    int t = -1;
    if(heap->size > 0){
        t = top(heap);
        swap(&heap->arr[0], &heap->arr[heap->size - 1]);
        heap->size--;
        Heapify(heap, 0);
    }
    return t;
}