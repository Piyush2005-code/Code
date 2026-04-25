/*
WAP to implement the insertion of nodes into an AVL tree and check whether the resulting tree is a valid AVL tree. 
Your main program should take the following input:
The number of nodes n to be inserted into the AVL tree. n integers representing the data of each node to be inserted.

Inputs: number of nodes and value of nodes.
Output: root node of resultant and "True " or "False" to represent validity.

input: 2 1 3
output :
2 1 3 
True
*/

//Solution:
#include <iostream>
#include <algorithm>

using namespace std;

// Class for AVL Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new AVL tree node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

//max definition:
int max(int a, int b){
    return (a > b)? a: b;
}

// Function to get the height of a node
int getHeight(Node* node) {
    if(node == nullptr) return 0;
    else return max(getHeight(node->right), getHeight(node->left)) + 1;
}

// Function to create a new AVL tree node
Node* createNode(int data) {
        return new Node(data);
}

// Function to right rotate subtree rooted with y
Node* rightRotate(Node* y) {
    // Implement this function to perform a right rotation
    Node* temp = y->left;
    y->left = temp->right;
    temp->right = y;
    return temp;
}

// Function to left rotate subtree rooted with x
Node* leftRotate(Node* x) {
    // Implement this function to perform a left rotation
    Node* temp = x->right;
    x->right = temp->left;
    temp->left = x;
    return temp;
}

// Get Balance factor of node N
int getBalance(Node* N) {
    // Implement this function to calculate and return the balance factor
    return getHeight(N->right) - getHeight(N->left);
}

// Function to insert a node in AVL tree and balance the tree
Node* insert(Node* root, int data) {
    // Implement this function to insert a node and balance the AVL tree
    if(root == nullptr) return  createNode(data);
    if(data > root->data) root->right = insert(root->right, data);
    else if(data < root->data) root->left = insert(root->left, data);
    else return root;
    
    
    int balance = getBalance(root);
    
    if(balance < -1 && getBalance(root->left) <= 0){
        return rightRotate(root);
    }
    if(balance < -1 && getBalance(root->left) > 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance > 1 && getBalance(root->right) >= 0){
        return leftRotate(root);
    }
    if(balance > 1 && getBalance(root->right) < 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

// Function to check if a tree is a valid AVL tree
bool isValidAVL(Node* root) {
    // Implement this function to check if a tree is a valid AVL tree
    if(abs(getBalance(root)) <= 1) return true;
    return false;
}

// Function to perform preorder traversal of the AVL tree
void preorderTraversal(Node* root) {
    // Implement this function to perform a preorder traversal and print nodes
    if(root == nullptr) return;
    cout<< root->data<< " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}


int main() {
    int n;

    cin >> n;
    Node* root = nullptr;


    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        root = insert(root, data);
    }


    preorderTraversal(root);
    cout << endl;

    if (isValidAVL(root)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
// Solution involves right and left Rotation of the AVL Nodes.
