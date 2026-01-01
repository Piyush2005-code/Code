/*
Build an AVL tree by inserting a predefined set of keys.
Allow the user to input a key to delete from the AVL tree.
Perform the necessary rotations to maintain the AVL tree's balance after deletion.
Display the tree's preorder traversal after the deletion to illustrate its balanced structure.

Inputs: 1) a integer value which represents "Number of nodes"; 2) Take node values ;3) Another input which represents target node to delete.
Output : Preorder traversal of tree
*/

//Solution:

#include<iostream>
using namespace std;

class Node {
public:
    int key;
    Node *left, *right;
    int height;
    Node(int data): key(data), left(nullptr), right(nullptr), height(1){}
};

// Utility function to get maximum of two integers
int max(int a, int b) {
    // TODO: Implement max function
    return (a > b)? a: b;
}

// Function to get height of the tree
int height(Node *N) {
    // TODO: Implement height function
    if(N == nullptr) return 0;
    return max(height(N->right), height(N->left)) + 1;
}

// Helper function to create a new node with the given key
Node* newNode(int key) {
    // TODO: Allocate memory for a new node and initialize it
    return new Node(key);
}

// Function to right rotate subtree rooted with y
Node* rightRotate(Node *y) {
    // TODO: Implement rightRotate function
    Node* temp = y->left;
    y->left = temp->right;
    temp->right = y;
    
    y->height = height(y);
    temp->height = height(temp);
    
    return temp;
}

// Function to left rotate subtree rooted with x
Node* leftRotate(Node *x) {
    // TODO: Implement leftRotate function
    Node* temp = x->right;
    x->right = temp->left;
    temp->left = x;
    
    x->height = height(x);
    temp->height = height(temp);
    
    return temp;
}

// Get Balance factor of node N
int getBalance(Node *N) {
    // TODO: Implement getBalance function
    return height(N->right) - height(N->left);
}


Node* invertTree(Node* root) {
    // Swap the left and right children of every node in the tree
    if(root == nullptr) return root;
    Node* temp = root->right;
    root->right = root->left;
    root->left = temp;
    // TODO: Implement the function
    root->left = invertTree(root->left);
    root->right = invertTree(root->right);
    return root;
}


// Recursive function to insert a key into the subtree rooted with node
// and returns the new root of the subtree.
Node* insert(Node* node, int key) {
    // TODO: Implement AVL tree insertion logic
    if(node == nullptr) return newNode(key);
    if(key < node->key) node->left = insert(node->left, key);
    else if(key > node->key) node->right = insert(node->right, key);
    else{
        return node;
    }
    // Remember to update the height of the node and balance the tree
    node->height = height(node);
    
    int balance = getBalance(node);
    
    if(balance > 1 && getBalance(node->right) >= 0){
        return leftRotate(node);
    }
    if(balance > 1 && getBalance(node->right) < 0){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    if(balance < -1 && getBalance(node->left) <= 0){
        return leftRotate(node);
    }
    if(balance < -1 && getBalance(node->left) > 0){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    return node;
}

// Recursive function to delete a node with given key from subtree with given root
// It returns root of the modified subtree.
Node* deleteNode(Node* root, int key) {
    // TODO: Implement AVL tree deletion logic
    if(root == nullptr) return root;
    
    if(key < root->key) root->left = deleteNode(root->left, key);
    else if(key > root->key) root->right = deleteNode(root->right, key);
    else{
        if(root->right == nullptr || root->left == nullptr){
            Node* temp = root->left? root->left: root->right;
            if(temp == nullptr){
                temp = root;
                root = nullptr;
            }
            else{
                *root = *temp;
            }
            delete temp;
        } else{
            Node* minRightValueNode = root->right;
            
            while(minRightValueNode->left != nullptr)
                minRightValueNode = minRightValueNode->left;
            
            root->key = minRightValueNode->key;
            
            root->right = deleteNode(root->right, minRightValueNode->key);
        }
    }
    
    if(root == nullptr){
        return root;
    }
    // Remember to update the height of the node and balance the tree
    root->height = max(height(root->left), height(root->right)) + 1;
    
    
    int balance = getBalance(root);
    
    if(balance < -1 && getBalance(root->left) <= 0){
        return rightRotate(root->left);
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

// A utility function to do preorder traversal of the tree
void preOrder(Node *root) {
    if(root != NULL) {
        cout<< root->key<< " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if(root!= NULL){
        inOrder(root->left);
        cout<< root->key<< " ";
        inOrder(root->left);
    }
}

int main() {
    Node *root = NULL;
    int n, key;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>key;
        root = insert(root, key);
    }
    inOrder(root);
    cout<< endl;
    inOrder(root);
    // preOrder(root);
    // cin>>key;
    // root = deleteNode(root, key);

    // preOrder(root);

    return 0;
}
