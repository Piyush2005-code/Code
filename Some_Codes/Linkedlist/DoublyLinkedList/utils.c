#include<stdio.h>
#include<stdlib.h>
#include "utils.h"


Node* append(Node* tail, int data){
    if(tail == NULL){
        Node* head = (Node*)malloc(sizeof(Node));
        head->data = data;
        head->next = NULL;
        head->prev = NULL;
        return head;
    }
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = (Node*)malloc(sizeof(Node));
    tail->next->data = data;
    tail->next->next = NULL;
    tail->next->prev = tail;
    return tail;
}

Node* insert(Node* ptr, int data, int idx){
    if(ptr == NULL){
        Node* head = (Node*)malloc(sizeof(Node));
        head->data = data;
        head->next = NULL;
        head->prev = NULL;
        printf("The pointer argument passed was NULL, so allocated new memory for the data and the pointer has been returned!...\n");
        return head;
    }
    while(ptr->prev != NULL){
        ptr = ptr->prev;
    }
    

    
    if(idx < size(ptr)){
        for(int i = 0; i < idx; i++){
            ptr = ptr->next;
        }
        
        
    }

}

int size(Node* ptr){
    if(ptr == NULL) return 0;
    while(ptr->prev != NULL) ptr = ptr->prev;
    int count = 0;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }
    return count;
}

void print(Node* ptr){
    if(ptr == NULL){
        printf("List empty!\n");
    }
    while(ptr->prev != NULL){
        ptr = ptr->prev;
    }
    while(ptr != NULL){
        if(ptr->next == NULL) printf("%d\n", ptr->data);
        else printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}