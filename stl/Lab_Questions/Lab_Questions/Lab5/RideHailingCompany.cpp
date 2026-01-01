/*
A ride-hailing company wants to keep track of all driver fares in real time. Each driver sets a base fare (an integer). Drivers can join or leave the system at any time, and riders can ask questions about the fares. The system should support four operations:
I X : Add a driver with fare X (ignore if already present).
D X :  Remove the driver with fare X (ignore if not present).
R X :  Find the rank of fare X (rank means its position in the sorted list of fares, starting from 1 for the smallest fare). If X is not present, print -1.
K K :  Find the K-th cheapest fare among all active drivers. If fewer than K drivers exist, print -1.
You are given Q operations, and you must process them in order. For every R and K query, print the answer on a new line.

Input Format: 
First line: an integer Q (number of operations).
Next Q lines: each operation in one of the following forms:



I X
D X
R X
K K

Output Format:
For every R or K query, print the result on a new line.


Sample I/p
10
I 300
I 150
I 500
I 100
I 250
R 150
K 3
D 150
R 150
K 3

Output:
2
250
-1
300
*/

//Solution:
#include <bits/stdc++.h>
using namespace std;

// -------- AVL Node Definition --------
struct Node {
    int key;
    int height;
    int size;
    struct Node *left, *right;
    
    Node(int key){
        this->key = key;
        this->height = 0;
        this->size = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
    
};

// // -------- Helper Functions ---------


// // -------- Utility Functions --------
// int height(struct Node* n) { /* TODO */ }
// int size(struct Node* n){
//     if(root->right == NULL && root->left == NULL) return 1;
//     else{
//         if(root->right == NULL) return size(root->left);
//         if(root->left == NULL) return size(root->right);
//         return size(root->right) + size(root->left);
//     }
// }
// void update(struct Node* n) { /* TODO */ }
// int getBalance(struct Node* n) { /* TODO */ }
// struct Node* newNode(int key) { /* TODO */ }

// // -------- Rotations --------
// struct Node* rotateRight(struct Node* y) { /* TODO */ }
// struct Node* rotateLeft(struct Node* x) { /* TODO */ }

// // -------- Balancing --------
// struct Node* balance(struct Node* n) {
    
// }

// // -------- Insert --------
// struct Node* insert(struct Node* root, int key) {
//     struct Node* newNode = new struct Node(key);
//     if(root == NULL) root = newNode;
//     else if(root->key > key){
//         insert(root->left, key);
//     }
//     else{
//         insert(root->right, key);
//     }
//     return root;
// }
int insert(int arr[], int x, int size){
    if(size == 0){
        arr[0] = x;
    }
    else if(size == 1){
        if(arr[0] > x){
            arr[1] = arr[0];
            arr[0] = x;
        }
        else{
            arr[1] = x;
        }
    }
    else{
        int l = 0;
        int r = 1;
        if(arr[0] > x){
            for(int i = size; i > 0; i--){
                arr[i] = arr[i - 1];
            }
            arr[0] = x;
        }
        else{
            while(arr[r] < x){
                r++; l++;
            }
            for(int i = size; i > r; i--){
                arr[i] = arr[i - 1];
            }
            arr[r] = x;
        }
    }
    return 1;
}
int erase(int arr[], int x, int size){
    int i = 0;
    for(; i < size; i++)
        if(arr[i] == x) break;
    for(int j = i; j < size - 1; j++) arr[j] = arr[j + 1];
    return 1;
}
// -------- Delete --------
// struct Node* minValueNode(struct Node* n) { /* TODO */ }
// struct Node* erase(struct Node* root, int key) { /* TODO */ }

// -------- Queries --------
int getRank(int arr[], int key, int size) {
    for(int i = 0; i < size; i++){
        if(arr[i] == key) return i + 1;
    }
    return -1;
}
int getKth(int arr[], int k, int size){
    return (size < k)? -1: arr[k -1];
}// -------- Driver Code --------
int main() {
    int Q; 
    cin>> Q;
    int arr[Q];
    int size;
    while (Q--) {
        char op; int x;
        cin>> op>> x;
        if (op == 'I'){
            insert(arr, x, size);
            size++;
        }
        else if (op == 'D'){
            erase(arr, x, size);
            size--;
        }
        else if (op == 'R') cout<< getRank(arr, x, size)<< endl;
        else if (op == 'K') cout<< getKth(arr, x, size)<< endl;
    }
    return 0;
}