#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* append(Node* head, int data);

bool check_for_cycle(Node* head);

Node* tail_of_list(Node* head);

void printList(Node* head);

bool check_for_cycle(Node* head);

bool check_for_cycle_correct(Node* head);

Node* return_pointer(Node* head, int i);

int size(Node* head);

#endif