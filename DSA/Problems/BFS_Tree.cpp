#include<iostream>
#include<queue>



using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int data){
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

class BST{
    public:
    Node* root = nullptr;

    void insert(int data){
        if(this->root == nullptr)
        this->root = new Node(data);
        else{
            Node* ptr = root;
            while(!(ptr->left == nullptr || ptr->right == nullptr)){
                if(data < ptr->val) ptr = ptr->left;
                else if(data > ptr->val) ptr = ptr->right;
                else return;
            }
            if(ptr->left == nullptr){
                ptr->left = new Node(data);
                return;
            }
            if(ptr->right == nullptr){
                ptr->right = new Node(data);
                return;
            }
            return;
        }
    }

    vector<int> BFS(){
        if(this->root == nullptr) return vector<int>(0);
        queue<Node*> q;
        q.push(root);
        vector<int> vec;
        int front;
        Node* curr;

        while(!q.empty()){
            curr = q.front();
            q.pop();
            
            vec.push_back(curr->val);

            if(curr->left) q.push(curr->left);
            else vec.push_back(-1);
            if(curr->right) q.push(curr->right);
            else vec.push_back(-1);
            
        }

        return vec;
    }

};




int main(){



}
