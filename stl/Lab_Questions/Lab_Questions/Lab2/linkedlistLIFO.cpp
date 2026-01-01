/*
Problem:
Given a linked list and a list of operations to be performed on the list, print the linked list after each operation.
There are two types of operations, insertion and deletion. Insertion involves inserting the given element at the front of the linked list, and deletion involves removing the element from the front of the linked list. This will demonstrate the Last In First Out (LIFO) operations in a linked list.

Input Format:
First line contains an integer n, the initial number of elements in the linked list.
Second line contains n integers, denoting the initial elements to be inserted in the linked list following the above explained insertion.
Third line contains an integer m, the number of operations to be performed.
Next m lines contain two integers each, a & b:
If a == 1, insert b at the front of the linked list.
If a == 2, b will always be -1; perform deletion from the front of the linked list.

Output Format:
Print m lines, showing the linked list after each operation.

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
10 5 4 3 2 1 NULL
5 4 3 2 1 NULL
4 3 2 1 NULL
20 4 3 2 1 NULL
*/

//Solution:
#include <iostream>
using namespace std;

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
        // complete this insert function
        if(head == NULL){
            head = new node(val, NULL); return;
        }
        node* newNode = new node(val, head);
        head = newNode;
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
    if(l.head == NULL){
        l.head = elem;
    }
    else{
        elem->next = l.head;
        l.head = elem;
    }
}

node* deletion_operation(LinkedList &l){
    // delete the elem from the front
    if(l.head == NULL) return l.head;
    node* del_ptr = l.head;
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
    int m, a, b; 
    cin>> m;
    for(int i = 0; i < m; i++){
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