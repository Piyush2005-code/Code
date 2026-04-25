/*
A Linked List is a linear data structure where elements, called nodes, are stored in a sequence. Each node contains a value and a reference (or pointer) to the next node in the sequence, allowing for dynamic memory allocation and efficient insertion or deletion of elements. The starting node of a linked list is called its head. 

Problem:
Given a linked list and a list of operations to be performed on the list, print the linked list after each operation. 
There are two types of operations, insertion and deletion. Insertion involves inserting the given element at the end of the linked list and deletion involves removing the element from the front of the linked list. Which will demonstrate the First In First Out (FIFO) operations in a linked list.

Input Format:
First line contains an integers n, the initial number of elements in the linked list.
Second line contains n integers, denoting the initial elements of linked list.
Third line contains an integer m.
Next m lines contain two integers each, a & b. 
                                      --- if a==1, insert b. 
                                      --- if a==2, b will be always -1, perform deletion.

Output Format:
Print m lines, the linked list after each operation.


Sample Test Case:
Input:
5
1 2 3 4 5
4
1 10
2 -1
2 -1
1 20

Output:
1 2 3 4 5 10 NULL
2 3 4 5 10 NULL
3 4 5 10 NULL
3 4 5 10 20 NULL
*/


//Solution:
#include <iostream>
using namespace std;

#define repeat(i,s,e) for(long long i=s;i<e;i++)

class node{
    public:
    int val;
    node* next;
    node(int v=0,node* nxt=NULL){
        val = v;
        next = nxt;
    }
};

class LinkedList{
    public:
    node* head;
    LinkedList(node* h=NULL){
        head = h;
    }
    void insert(int val){
        node* newNode = new node(val, NULL);
        if(head == NULL) head = newNode;
        else{
            node* ptr = head;
            while(ptr->next != nullptr) ptr = ptr->next;
            ptr->next = newNode;
        }
    }

    void printLinkedList(){
        // don't alter this printing function
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

void insertion_operation(LinkedList &l,node* elem){
    if(l.head == NULL) l.head = elem;
    else{
        node* head = l.head;
        while(head->next != NULL) head = head->next;
        head->next = elem;
    }
}

node* deletion_operation(LinkedList &l){
    node* head = l.head;
    // if(head == NULL){
    //     cout<< "The List is already empty.\n"; return NULL;
    // }
    if(head == NULL) return head;
    node* del_ptr = head;
    l.head = l.head->next;
    delete del_ptr;
    return l.head;
}

int main(){
    // initialize the linked list 
    LinkedList list = LinkedList(NULL);
    
    // take input for linked list
    int n, x;
    cin>> n;
    for(int i = 0; i < n; i++){
        cin>> x;
        list.insert(x);
    }
    // take input for the operations
    int p, a, b;
    cin>> p;
    for(int i = 0; i < p; i++){
        cin>> a>> b;
        if(a == 1){
            insertion_operation(list, new node(b, NULL));
            list.printLinkedList();
        }
        else{
            deletion_operation(list);
            list.printLinkedList();
        }
    }
    
    // perform operation and after the operation print the list
    
    return 0;
}