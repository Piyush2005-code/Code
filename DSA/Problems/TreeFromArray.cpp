#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class TreeNode{
    int val;
    public:
        TreeNode* left = NULL;
        TreeNode* right = NULL;
        int height;
        int balanceFactor;
    
        TreeNode(int value): val(value), height(0), balanceFactor(0){}

        int getValue(){
            return val;
        }
};

class BinaryTree{

    private:
        TreeNode* root;
    
    public:
        BinaryTree(int val): root(new TreeNode(val)){}
        BinaryTree(): root(nullptr){}

        TreeNode* getroot(){ return root;}
        void setRoot(TreeNode* rootValue){this->root = rootValue;}
};

// TreeNode* insert(TreeNode* root, int index, vector<int> arr){
//     if(root == nullptr) return new TreeNode(arr[index]);
//     else{

//     }
// }

TreeNode* insert(TreeNode* root, int val){
    if(root == nullptr){
        return new TreeNode(val);
    }
    else{
        if(val < root->getValue()){
            root->left = insert(root->left, val);
            return root;
        }
        if(val > root->getValue()){
            root->right = insert(root->right, val);
            return root;
        }
        return root;    
    }
}

void balanceTree(TreeNode* root){
    return;
}

void preorderTraversal(TreeNode* root){
    if(root == nullptr) return;
    cout<< root->getValue()<< " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    return;
}

void inorderTraversal(TreeNode* root){
    if(root == nullptr) return;
    inorderTraversal(root->left);
    cout<< root->getValue()<< " ";
    inorderTraversal(root->right);
    return;
}

void postorderTraversal(TreeNode* root){
    if(root == nullptr) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<< root->getValue()<< " ";
    return;
}


int main(){

    int n;
    cin>> n;
    vector<int> arr(n);
    BinaryTree BST;

    for(int &x: arr){
        cin>> x;
    }
    // for(int x: arr){cout<< x<< " ";}

    for(int x: arr){
        BST.setRoot(insert(BST.getroot(), x));
    }

    // preorderTraversal(BST.getroot());
    // inorderTraversal(BST.getroot());
    // postorderTraversal(BST.getroot());

    


}