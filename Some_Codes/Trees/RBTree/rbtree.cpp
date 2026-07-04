#include<iostream>
#include<string>


using namespace std;

template <typename T>
struct TreeNode{
    int val;
    TreeNode* right, left, parent;
    TreeNode() : val(0), left(nullptr), right(nullptr), parent(nullptr){}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr), parent(nullptr){}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right), parent(nullptr){}
    TreeNode(int val, TreeNode* left, TreeNode* right, TreeNode* parent) : val(val), left(left), right(right), parent(parent){}
};


class RBTree{
    private:
        void leftRotate(TreeNode* x){
            
        }


};
