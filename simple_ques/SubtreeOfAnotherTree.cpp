#include<iostream>

struct TreeNode{
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool equal(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2) return true;
        else if(root1 && root2){
            return root1->val == root2->val && equal(root1->right, root2->right) && equal(root1->left, root2->left);
        }
        else return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return false;
        else if(root && subRoot)
            return equal(root, subRoot) || isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);
        else return false;
    }
};

//Correct Solution working
