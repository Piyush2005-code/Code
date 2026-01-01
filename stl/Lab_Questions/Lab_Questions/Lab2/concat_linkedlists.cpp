// A Linked List is a linear data structure where elements, called nodes, are stored in a sequence. Each node contains a value and a reference (or pointer) to the next node in the sequence, allowing for dynamic memory allocation and efficient insertion or deletion of elements. The starting node of a linked list is called its head. 

// Problem:
// Given heads of two linked lists, concatenate the linked lists by connecting both of them. Connect the head of linked list 2 with the last node of linked list 1, i.e. concatenate the linked lists to create one big list. 

// Input Format:
// First line contains two integers n and m, the lengths of the two linked lists.
// Second line contains n integers, values for linked list 1
// Third line contains m integers, values for linked list 2

// Output Format:
// Print the resulting big linked list


// Sample Test Case:
// Input:
// 2 3
// 1 2
// 3 4 5

// Output:
// 1 2 3 4 5 NULL


//Solution:
#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    // Constructor overloading.
    Node(int data, Node* next): data(data), next(next){}
    Node(int data): data(data), next(NULL){}

};

class LinkedList{
    public:
    Node* head = NULL;

    void insert(int data){
        Node* newNode = new Node(data);
        if(head == NULL) head = newNode;
        else{
            Node* ptr = this->head;
            while(ptr->next != NULL) ptr = ptr->next;
            ptr->next = newNode;
        }
    }

    void printLinkedList(){
        Node* curr = this->head;
        if(curr == NULL) cout<< "The LinkedList is EMPTY.";
        else{
            while(curr){
                cout<< curr->data<< " ";
                curr = curr->next;
            }
        }
        cout<< endl;
    }

};

Node* concatenate(Node* head1, Node* head2){
    
    if(head1 == NULL) return head2;
    else{
        Node* ptr = head1;
        while(ptr->next != NULL) ptr = ptr->next;
        ptr->next = head2;
    }
    return head1;
}


int main(){

    // Create the LinkedList instances
    LinkedList list1;
    LinkedList list2;

    // Take the input of the LinkedLists
    int n, m, x = 0;
    cin>> n>> m;
    for(int i = 0; i < n; i++){
        cin>> x;
        list1.insert(x);
    }
    for(int i = 0; i < m; i++){
        cin>> x;
        list2.insert(x);
    }

    // Implement the concatenate function
    Node* head1 = concatenate(list1.head, list2.head);

    // Print the Concatenated List
    Node* curr = head1;
    while(curr){
        cout<< curr->data<< " ";
        curr = curr->next;
    }
    cout<< "NULL";

}


// Solution passed.