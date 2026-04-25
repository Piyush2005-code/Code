#include<iostream>
#include<vector>


class TreeNode{
    private:
        int val;

    public:
        TreeNode* left;
        TreeNode* right;
        int height;
        int balanceFactor;
        TreeNode(int value): val(value), left(nullptr), right(nullptr), height(0), balanceFactor(0) {}
};


class AVLTree{
    private:
        TreeNode* root;

        TreeNode* insert(TreeNode* root, int val){

        }

    public:
        



};


int main(){

    
}
