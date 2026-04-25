/*
Ash has two binary trees, “Tree-1" and “Tree-2”, where each node of the tree has a positive integer value. Now Ash wants to give these trees to Serena, but he can't decide which Tree should be gifted. So to keep the good traits of both the trees, he decides to merge them in a common binary tree and gift this merged tree to Serena. But since Ash is good in catching Pokemons and not in coding, you need to help him in merging these binary trees.

Rules:
1. If two nodes overlap, the sum of their values should be the new value of the merged node and If either node in the overlapping position is null, the non-null node should be used as the value of the new node.
2. The binary tree contains only positive integer elements. -1 denotes a null node.

Input Format:
First line contains a single integer n, denoting the number of nodes in the 1st binary tree.
Second line contains the n integers, nodes of the 1st binary tree in level order.
Third line contains a single integer m, denoting the number of nodes in the 2nd binary tree.
Fourth line contains the m integers, nodes of the 2nd binary tree in level order.

Output Format:
Print the inorder traversal of the merged binary tree.

Sample Input:
7
1 2 3 -1 4 -1 5
7
1 2 2 6 -1 7 -1

Output:
6 4 4 2 7 5 5
*/

//Solution:
#include <iostream>
#include <vector>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class binary_tree {
public:
    node* root = nullptr;

    void make_binary_tree_from_array(vector<int>& arr) {
        this->root = construct_binary_tree_from_level_order_array(arr, 0);
    }

    node* construct_binary_tree_from_level_order_array(vector<int>& arr, size_t index) {  
        //Implement your code Here
        
        }
};

// Merge Trees Function
node* merge_trees(node* root1, node* root2) {
    //Implement your code here
}

// Inorder Traversal
void inorder(node* root) {
    //Implement your code here
}

int main() {
    int n, m;
    
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];  // Take the level-order of Tree 1

    cin >> m;
    vector<int> brr(m);
    for (int i = 0; i < m; i++) cin >> brr[i];  // Take the level-order of Tree 2

    binary_tree tree1, tree2;
    tree1.make_binary_tree_from_array(arr);
    tree2.make_binary_tree_from_array(brr);

    node* mergedRoot = merge_trees(tree1.root, tree2.root);

    inorder(mergedRoot);  // Print the inorder traversal of the merged tree
    cout << endl;

    return 0;
}