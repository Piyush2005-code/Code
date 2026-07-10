#ifndef HEAP_HPP
#define HEAP_HPP

struct Heap{
    int *arr;
    int capacity;
    int size;
};

struct Heap* initHeap(int capacity);

void swap(int* a, int* b);

int getParent(int curr);

int getLeftChild(int curr);

int getRightChild(int curr);

void Heapify(struct Heap* heap, int i);

void insertKey(struct Heap *heap, int key);

int top(struct Heap *heap);

void printHeap(struct Heap* heap);

int extractTop(struct Heap *heap);


#endif