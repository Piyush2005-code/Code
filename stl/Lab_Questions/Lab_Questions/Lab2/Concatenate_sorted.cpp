/*
A Linked List is a linear data structure where elements, called nodes, are stored in a sequence. Each node contains a value and a reference (or pointer) to the next node in the sequence, allowing for dynamic memory allocation and efficient insertion or deletion of elements. The starting node of a linked list is called its head. 

Problem:
Given heads of two linked lists, concatenate the linked lists such that the concatenated list is sorted. (You can assume that the original lists are sorted already)

Input Format:
First line contains two integers n and m, the lengths of the two linked lists. 0 <= n,m <= 100
Second line contains n integers, values for linked list 1. This line will not be present if n=0
Third line contains m integers, values for linked list 2. This line will not be present if m=0

Output Format:
Print the resulting big linked list.


Sample Test Case:
Input:
2 3
1 2
1 2 5

Output:
1 1 2 2 5 NULL
*/

//Solution Template:
// #include <iostream>
// using namespace std;

// class node{
//     public:
//     int val;
//     node* next;
//     node(int v=0,node* nxt=NULL){
//         val = v;
//         next = nxt;
//     }
// };

// class LinkedList{
//     public:
//     node* head;
//     LinkedList(node* h=NULL){
//         head = h;
//     }
//     void insert(int val){
//         // write your indertion logic here.
//     }

//     void printLinkedList(){
//         if (head==NULL){
//             cout<<"EMPTY\n";
//             return;
//         }
//         node* curr = head;
//         while(curr){
//             cout<<curr->val<<' ';
//             curr = curr->next;
//         }
//         cout<<"NULL\n";
//     }
// };

// node* concatenate(node* head1,node* head2){
//     // well not needed but you can get it from previous 
// }

// node* sortedConcatenate(node* head1,node* head2){
//     // Implement the required logic here
// }

// int main(){
//     Linked

//     // take input and make the linked lists

//     // call the sortedConcatenate function

//     // print the new sorted big linked list using printLinkedList
    
//     return 0;
// }

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
        node* newNode = new node(val, NULL);
        if(head == NULL){
            head = newNode;
        }
        else{
            node* ptr = head;
            while(ptr->next != NULL) ptr = ptr->next;
            ptr->next = newNode;
        }
    }

    void insert_sorted(int val) {
        node* newNode = new node(val);
        if(head == NULL){
            head = newNode;
        }
        else if(head ->next == NULL){
            if(head->val <= newNode->val) head->next = newNode;
            else{
                newNode->next = head;
                head = newNode;
            }
        }
        else{
            if(head->val >= val){
                newNode->next = head;
                head = newNode;
            }
            else{
                node* l = head;
                node* r = head->next;
                while(r != NULL){
                    if(val > l->val && val <= r->val){
                        l->next = newNode;
                        newNode->next = r; return;
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
            cout<<curr->val<<' ';
            curr = curr->next;
        }
        cout<<"NULL\n";
    }
};



// node* concatenate(node* head1,node* head2){
//     // well not needed but you can get it from previous 
// }

node* sortedConcatenate(node* head1,node* head2){
    LinkedList big_list = LinkedList(NULL);
    // while(head1 != NULL && head2 != NULL){
    //     if((head1->val) >= (head2->val)){
    //         big_list.insert(head2->val);
    //         head2 = head2->next;
    //     }
    //     else{
    //         big_list.insert(head1->val);
    //         head1 = head1->next;
    //     }
    // }
    while(head2){
        big_list.insert_sorted(head2->val);
        head2 = head2->next;
    }
    while(head1){
        big_list.insert_sorted(head1->val);
        head1 = head1->next;
    }
    return big_list.head;
}

int main(){
    // Initialize two linked lists
    LinkedList l1 = LinkedList(NULL);
    LinkedList l2 = LinkedList(NULL);

    // take input and make the linked lists
    int n, m, x;
    cin>> n>> m;
    for(int i = 0; i < n; i++){
        cin>> x;
        l1.insert(x);
    }
    for(int j = 0; j < m; j++){
        cin>> x;
        l1.insert(x);
    }
    // call the sortedConcatenate function
    node* head_big = sortedConcatenate(l1.head, l2.head);

    // print the new sorted big linked list using printLinkedList
    while(head_big){
        cout<< head_big->val<< " ";
        head_big = head_big->next;
    }
    cout<< "NULL";
    return 0;
}