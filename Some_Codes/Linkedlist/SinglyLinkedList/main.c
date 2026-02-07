#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "utils.h"



// This is the main function for finding and testing whether the linked list has a loop or not.
int main(){
    int n;
    Node* head = NULL;
    scanf("%d", &n);
    int x;
    int loop_start;
    int loop_end;
    int want_loops;

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        head = append(head, x);
    }

    printf("Enter 1 if you want loops, else 0: ");
    scanf("%d", &want_loops);

    if(want_loops){
        printf("Enter the index of loop start: ");
        scanf("%d", &loop_start);
        printf("Enter the index of loop_end: ");
        scanf("%d", &loop_end);
        Node* start = return_pointer(head, loop_start);
        Node* end = return_pointer(head, loop_end);
        end->next = start;
    }

    printf("%d__\n", check_for_cycle(head));

    // printList(head);
}



