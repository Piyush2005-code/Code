#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct ListNode{
    int data;
    struct ListNode* next;
    struct ListNode* prev;
} Node;

Node* append(Node* tail, int data);

Node* insert(Node* ptr, int data, int idx);

void print(Node* ptr);

#endif