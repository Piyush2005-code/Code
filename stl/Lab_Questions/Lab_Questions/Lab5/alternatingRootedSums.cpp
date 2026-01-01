/*
For any Binary Tree, write a program that calculates the number of rooted paths, whose alternating sum matches the required targets. Rooted Paths are paths that start from the root of the tree, and may end on any node in the tree. Alternating Sum of a rooted path is the value obtained by alternatingly adding and subtracting node values from the root to the path end. For e.g., for a path 5 -> 4 -> 1 -> 3 -> 2, in a tree rooted at 5, the alternating Sum is 5 - 4 + 1 - 3 + 2 = 1.

Input format:
n and k, where n is the size of the level-order array representation of the BT, and k is the number of targets to check
The level-order array representation of the BT (-1 for null nodes)
The 'k' targets 'ti' (i = 1 to k)
Output:
'k' numbers 'ci' (i = 1 to k) giving the count of paths satisfying alternating path sum of 'ti'

E.g.
Input:
7 3
1 3 2 6 1 -1 5
4 -1 0
Output:
2 2 0

Explanation: The given tree is
          1
    3         2
6     1    null   5
Here the rooted paths 1->3->6 and 1->2->5 give the alternating sum of 4, hence the first count is 2. 
Similarly, the rooted paths 1->2 and 1->3->1 give the alternating sum of -1, hence the second count is also 2.
However, no rooted path gives the alternating sum of 0, hence the third count is 0.
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
        // Implement any required node variables/methods/constructors here
        Node(int dataValue): data(dataValue), left(nullptr), right(nullptr){}
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
    
    int countOfPaths(Node* root, int target, int sign){
        if(root == nullptr) return 0;
        else if(root->left == nullptr && root->right == nullptr && target == 0)
            return 1;
        else{
            return countOfPaths(root->left, target - sign * (root->data), -sign) + countOfPaths(root->right, target - sign * (root->data), -sign);
        }
    }
    
    void alternating_path_sum(int *targets, int k){
        //Implement your main logic here
        for(int i = 0; i < k; i++){
            int targetSum = targets[i];
            int count = countOfPaths(this->root, targetSum, 1);
            std::cout<< count<< " ";
        }
    }
};

int main() {
    BinaryTree tree;
    int n, data, k;
    std::cin >> n >> k;
    int *arr = new int[n];
    int *targets = new int[k];
    
    for(int i = 0; i < n; i++) {
        std::cin >> data;
        arr[i] = data;
    }
    
    for(int i = 0; i < k; i++) {
        std::cin >> data;
        targets[i] = data;
    }
    
    tree.make_BT_from_array(arr,n);
    tree.alternating_path_sum(targets, k);
    return 0;
}