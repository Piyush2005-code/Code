#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int val;
    int height;
    Node* left;
    Node* right;
    Node(int data): val(data), left(nullptr), right(nullptr), height(0) {}
};


class Tree{
    public:
    Node* rootNode;
    
    Tree(): rootNode(nullptr) {}

    Node* rightRotate(Node* root){
        Node* temp = root->left;
        root->left = temp->right;
        temp->right = root;
        return temp;
    }

    Node* leftRotate(Node* root){
        Node* temp = root->right;
        root->right = temp->left;
        temp->left = root;
        return temp;
    }

    Node* insert(Node* root, int data){
        if(root == nullptr){
            
        }
    }


};
