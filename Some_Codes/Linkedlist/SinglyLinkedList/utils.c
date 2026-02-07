#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "utils.h"

Node* append(Node* head, int data){
    if(head == NULL){
        head = (Node*)malloc(sizeof(Node));
        head->data = data;
        head->next = NULL;
        return head;
    }
    Node* ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = (Node*)malloc(sizeof(Node));
    ptr = ptr->next;
    ptr->data = data;
    ptr->next = NULL;
    return head;
}

Node* tail_of_list(Node* head){
    if(head == NULL) return NULL;
    Node* ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    return ptr;
}

int size(Node* head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}

Node* return_pointer(Node* head, int i){
    int sizeoflist = size(head);
    if(i >= sizeoflist || i < -sizeoflist) return NULL;
    while(i < 0){
        i += sizeoflist;
    }
    for(int j = 0; j < i; j++){
        head = head->next;
    }
    return head;
}

void printList(Node* head){
    if(head == NULL){
        printf("List empty!");
        return;
    }
    
    Node* ptr = head;
    while(ptr != NULL){
        if(ptr->next != NULL){
            printf("%d ", ptr->data);
        }
        else{
            printf("%d", ptr->data);
        }
        ptr = ptr->next;
    }
    printf("\n");
    return;
}

// Check for loops in a linked list:
bool check_for_cycle(Node* head){
    if(head == NULL) return false;
    bool visited[100] = {false};
    int x = head->data;
    Node* ptr = head;
    while(visited[x] == false && ptr != NULL){
        x = ptr->data;
        visited[ptr->data] = true;
        ptr = ptr->next;
        if(ptr != NULL) x = ptr->data;
    }
    if(ptr == NULL) return false;
    else return visited[x] == true;
}


bool check_for_cycle_correct(Node* head){

    
}
