#include<iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution{
    public:
        int goodNodesRec(TreeNode* root, int prevMax){
            if(!root) return 0;
            if(!root->right && !root->left){
                return root->val >= prevMax;
            }
            else{
                int curr = root->val >= prevMax;
                prevMax = (root->val > prevMax ? root->val : prevMax);
                int right = goodNodesRec(root->right, prevMax);
                int left = goodNodesRec(root->left, prevMax);
                return curr + right + left;
            }
        }        

        int goodNodes(TreeNode* root){
            return 1 + goodNodesRec(root->left, root->val) + goodNodesRec(root->right, root->val);
        }
};


