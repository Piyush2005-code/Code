/*
Given an unsorted linked list, your task is to return the second-highest element in the list. If the list contains less than two distinct elements, return NULL.

Input Format:
First line of input contains an integer n, representing the number of elements in the linked list initially.
A second line contains n space-separated integers representing the elements of the linked list.

Output Format:
The code should print the second highest element in the linked list and if there are less than 2 elements in the linked list, it should output "NULL".

Sample Test Case:
Input:
5
4 7 2 6 9

Output:
7
*/

//Solution:
#include <iostream>
using namespace std;

class node {
public:
    // Define node attributes.
    int val;
    node* next;

    node(int data, node* next = NULL){
        this->val = data;
        this->next = next;
    }
};

class LinkedList {
public:
    node* head;
    LinkedList(node* h = NULL) {
        head = h;
    }

    void insert(int val){
        if(head == NULL) head = new node(val);
        else{
            node* newNode = new node(val);
            node* ptr = head;
            while(ptr->next != NULL) ptr = ptr->next;
            ptr->next = newNode;
        }
    }

    void printLinkedList() {
        if (head == NULL) {
            cout << "EMPTY\n";
            return;
        }
        node* curr = head;
        while (curr) {
            cout << curr->val << ' ';
            curr = curr->next;
        }
        cout << "NULL\n";
    }

    node* second_highest() {
        if(head == NULL)return NULL;
        if(head->next == NULL)return NULL;
        int max = -1111;
        int second_max = -11111;
        node* curr = head;
        while(curr){
            if(max < curr->val)
                max = curr->val;
            curr = curr->next;
        }
        curr = head;
        while(curr){
            if(curr->val < max && second_max < curr->val){
                second_max = curr->val;
            }
            curr = curr->next;
        }
        curr = head;
        while(curr){
            if(second_max == curr->val){
                return curr;
            }
            curr = curr->next;
        }
        return NULL;
        
    }
};

int main() {
    // Initialize the linked list.
    LinkedList list = LinkedList();
    
    // Take the input to linked list.
    int n, x;
    cin>> n;
    for(int i = 0; i < n; i++){
        cin>> x;
        list.insert(x);
    }

    
    node* result = list.second_highest();

    if (result) {
        cout << result->val << endl;
    } else {
        cout << "NULL" << endl;
    }

    return 0;
}