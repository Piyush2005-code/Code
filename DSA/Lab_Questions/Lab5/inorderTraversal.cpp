/*
You are given a list of elements, including possible null values, to create a Binary Search Tree (BST). 

Input:
1. Number of elements (N): An integer representing the total number of elements
2. Elements: A list of integers

Output:
Print the in-order traversal of the constructed BST, omitting the `null` values.

Example:

Input:
Number of elements: 5
Elements: 50, 30, 20, 40, 70

Output:
In-order Traversal: 20, 30, 40, 50, 70

Explanation:
The constructed BST is:
       50
      /  \
    30   70
   /  \
 20   40

Hence, the "in-order" traversal is => 20, 30, 40, 50, 70
*/

//Solution:

#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
    
    public:
    vector<int> inOrderTraversal(int n) {
        
        Node* insert(Node* root){
            
        }
        
        vector<int> arr(n, 0);
        for(int i = 0; i < n; i++) cin>> arr[i];
        
        
    }
};

int main() {
    int n;
    cin >> n;
    
    BST bst;
    
    vector<int> inOrder = bst.inOrderTraversal(n);
    for (int val : inOrder) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}