#include<stdio.h>
#include "utils.h"


int main(){

    int n;
    scanf("%d", &n);
    Node* head = NULL;
    Node* tail = NULL;
    int data;
    for(int i = 0; i < n; i++){
        scanf("%d", &data);
        if(i == 0) {
            head = append(head, data);
            tail = head;
        }
        else {
            tail = append(tail, data);
        }
    }

    print(head);

}