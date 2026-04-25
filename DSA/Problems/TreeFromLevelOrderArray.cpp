#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int data): val(data), left(nullptr), right(nullptr) {}
};

class BinaryTree{
    public:
    Node* root = nullptr;

    //Recursive:
    Node* TreeFromArray(Node* root, int arr[], int i, int n){
        if(i < n && arr[i] != -1){
            root = new Node(arr[i]);
        }
        else return root;
        cout<< "check1\n";
        root->left = TreeFromArray(root->left, arr, 2 * i + 1, n);
        cout<< "check2\n";
        root->right = TreeFromArray(root->right, arr, 2 * i + 2, n);
        cout<< "check3\n";
        return root;
    }

    void preOrderTraversal(Node* root){
        if(root == nullptr) return;
        cout<< root->val<< " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

    void inOrderTraversal(Node* root){
        if(root == nullptr) return;
        inOrderTraversal(root->left);
        cout<< root->val<< " ";
        inOrderTraversal(root->right);
    }

    void inOrder(){
        inOrderTraversal(root);
    }

};




int main(){

    int n;
    cin>> n;

    int arr[n];
    int i = 0;
    while(i < n){
        cin>> arr[i]; i++;
    }

    BinaryTree BTree;
    BTree.root = BTree.TreeFromArray(BTree.root, arr, 0, n);

    BTree.inOrder();
}

//Solved