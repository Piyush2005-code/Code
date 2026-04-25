/*
Given a linked list head, remove all the duplicates from the list and return the final list in a  sorted order.
input 1-2-3-3-4-4-5
output : 1-2-5
*/

//Solution:

#include <iostream>
#include <cstdlib>

using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
};

// Function to delete duplicate elements from a sorted singly-linked list
ListNode* deleteDuplicates(ListNode* head) {
    // Implement this function to remove duplicate elements from the linked list.
    // Return the head of the modified list.
    int N = 0;
    ListNode* ptr = head;
    while(ptr){
        N++; ptr = ptr->next;
    }
    int arr[N];
    ptr = head;
    for(int i = 0; i < N; i++){
        arr[i] = ptr->val;
        ptr = ptr->next;
    }
    
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(arr[i] == arr[j]){
                arr[j] = -9999;
            }
        }
    }
    
    // freeList(head);
    head = nullptr;
    head = new ListNode;
    head->val = arr[0];
    head->next = nullptr;
    ptr = head;
    
    for(int i = 1; i < N; i++){
        if(arr[i] != -9999){
            ptr->next = new ListNode;
            ptr = ptr->next;
            ptr->val = arr[i];
            ptr->next = nullptr;
        }
    }
    
    return head;
}



// Function to sort a singly-linked list in ascending order
// ListNode* sortList(ListNode* head) {
//   // Implement this function to sort the linked list in ascending order.
//     // Return the head of the sorted list.
//     int N = 0;
//     ListNode* ptr = head;
//     while(ptr){
        
//     }
// }

// Function to print the elements of a singly-linked list
void printList(ListNode* head) {
// Implement this function to print the elements of the linked list.
    ListNode* ptr = head;
    while(ptr){
        cout<< ptr->val;
        if(ptr->next != nullptr) cout<< "-";
        ptr = ptr->next;
    } cout<< "\n";
}
   
// Function to create a singly-linked list from an array of digits
ListNode* createList(const char* digits) {
    ListNode* head = nullptr;
    ListNode* current = nullptr;

    for (int i = 0; digits[i] != '\0'; ++i) {
        ListNode* newNode = new ListNode;
        newNode->val = digits[i] - '0';
        newNode->next = nullptr;

        if (current == nullptr) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    return head;
}

// Function to free the memory allocated for a singly-linked list
void freeList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
}

int main() {

char digits[100];

    cin >> digits;

    ListNode* head = createList(digits);

    printList(head);

    ListNode* result = deleteDuplicates(head);
    printList(result);
    // ListNode* sortedResult = sortList(result);

    // printList(sortedResult);

    // freeList(sortedResult);

    return 0;
}