/*
Write a code to give alternating level-order traversal of a BT. In alternating level-order traversal, you shall alternate  between going left to right, and right to left for every consecutive level of the BT.
The BT contains only positive integer elements. -1 denotes a null node. Separate the nodes with a space '  ', and end the levels with a bar '|'. 

Input format:
Size of the level order array
A single line giving the nodes of the graph in level order.
Output format:
The alternating level order traversal (without null nodes).


E.g.
Input:
7
1 2 3 -1 4 -1 5
Output:
1 | 3 2 | 4 5 | 

Explanation:
The input tree is 
        1 
    2       3
-1   4   -1    5
Traversing the first level from left-to-right gives the sequence '1', then the second level from right-to-left gives '3 2', finally third level from left-to-right again gives '4 5' (omit the null nodes).
*/

//Solution:
#include <iostream>

class BinaryTree{
    public:
    class Node {
        public:
        int data;
        Node* left;
        Node* right;
        
        Node(): data(0), left(nullptr), right(nullptr) {}
        
        Node(int val): data(val), left(nullptr), right(nullptr) {}
    };
    
    Node* root = nullptr;
    
    void make_BT_from_array(int *arr, int size)
    {
        this->root = BT_from_level_order_array(arr, 0, size);
    }
    
    Node* BT_from_level_order_array(int *arr, int index, int size){

        if (index < size && arr[index] != -1) {
            Node* newnode = new Node(arr[index]);
            newnode->left = BT_from_level_order_array(arr, 2 * index + 1, size);
            newnode->right = BT_from_level_order_array(arr, 2 * index + 2, size);
            return newnode;
        }
        return nullptr;
    }
    
    void alternatingLevelOrderTraversal() {
        // Implement logic for alternating level order traversal here
        int size(Node* root){
            if(root == nullptr) return 0;
            return size(root->left) + size(root->right) + 1;
        }
        
        int size = size(this->root);
    }
    
};

int main() {
    BinaryTree tree;
    int n, data;
    std::cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        std::cin >> data;
        arr[i] = data;
    }
    
    tree.make_BT_from_array(arr,n);
    tree.alternatingLevelOrderTraversal();
    return 0;
}