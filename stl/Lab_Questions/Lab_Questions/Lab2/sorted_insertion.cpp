/*
Given an array of elements, insert all the elements in a Linked List in sorted order. The insertion function should be called everytime you add an element to the linked list and it should be implemented in such a way that the inserted element goes to its correct position in the sorted order.
NOTE : You must NOT sort the array and then create a Linked List.

Input Format : First line of the input contains an integer 'n', representing the size of the input array. Next line contains n integers representing the elements in the array.

Output Format : Print the elements in the sorted linked list.

Example Input : 
5
3 11 9 16 15
Example Output : 
3 9 11 15 16*/


//Solution Template:
/*
#include <iostream>
using namespace std;

class node {
public:
    // Define node attributes here.
};

class LinkedList {
public:
    node* head;
    LinkedList(node* h = NULL) {
        head = h;
    }
    
    void insert_sorted(int val) {
        // Add insertion logic here.
    }

    void printLinkedList(){
        if (head==NULL){
            cout<<"EMPTY\n";
            return;
        }
        node* curr = head;
        while(curr){
            cout<<curr->val<<' ';
            curr = curr->next;
        }
        cout<<"NULL\n";
    }
};

int main() {
    LinkedList list;

    // Add your code here.

    return 0;
}
    */


// Solution:
#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        this->next = NULL;
    }
    node(int data, node* next){
        this->data = data;
        this->next = next;
    }
};

class LinkedList {
public:
    node* head;
    LinkedList(node* h = NULL) {
        head = h;
    }
    
    void insert_sorted(int val) {
        node* newNode = new node(val);
        if(head == NULL){
            head = newNode;
        }
        else if(head ->next == NULL){
            if(head->data <= newNode->data) head->next = newNode;
            else{
                newNode->next = head;
                head = newNode;
            }
        }
        else{
            if(head->data >= val){
                newNode->next = head;
                head = newNode;
            }
            else{
                node* l = head;
                node* r = head->next;
                while(r != NULL){
                    if(val > l->data && val <= r->data){
                        l->next = newNode;
                        newNode->next = r;
                        return;
                    }
                    l = l->next;
                    r = r->next;
                }

                l->next = newNode;
            }
            
        }
    }

    void printLinkedList(){
        if (head==NULL){
            cout<<"EMPTY\n";
            return;
        }
        node* curr = head;
        while(curr){
            cout<<curr->data<<' ';
            curr = curr->next;
        }
        cout<<"NULL\n";
    }
};

int main() {
    LinkedList list;

    int n, x;
    cin>> n;
    for(int i = 0; i < n; i++){
        cin>> x;
        list.insert_sorted(x);
    }
    
    list.printLinkedList();
    return 0;
}