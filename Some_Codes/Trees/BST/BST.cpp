#include<iostream>


using namespace std;


struct Node{
    int val;
    Node *left, *right;
    Node(int val) : val(val), left(nullptr), right(nullptr){}
    Node(int val, Node* left, Node* right) : val(val), left(left), right(right){}
};


class BST{
    private:
        Node* root;

        Node* insertNode(Node* root, int val){
            if(root == nullptr) return new Node(val);

            if(val < root->val) root->left = insertNode(root->left, val);
            else if(val > root->val) root->right = insertNode(root->right, val);
            
            return root;
        }

        void preOrderTraverse(Node* root){
            if(root == nullptr) return;
            cout << root->val << " ";
            preOrderTraverse(root->left);
            preOrderTraverse(root->right);
        }

        void inOrderTraverse(Node* root){
            if(root == nullptr) return;
            inOrderTraverse(root->left);
            cout << root->val << " ";
            inOrderTraverse(root->right);
        }

        void postOrderTraverse(Node* root){
            if(root == nullptr) return;
            postOrderTraverse(root->left);
            postOrderTraverse(root->right);
            cout << root->val << " ";
        }

        Node* searchTree(Node* root, int val){
            if(root == nullptr) return nullptr;
            if(root->val < val) return searchTree(root->right, val);
            else if (val < root->val) return searchTree(root->left, val);
            else return root;
        }

        Node* getInorderSuccessor(Node* root){
            root = root->right;
            while(root->left != nullptr)
                root = root->left;
            return root;
        }

        Node* getInorderPredecessor(Node* root){
            root = root->left;
            while(root->right != nullptr){
                root = root->right;
            }
            return root;
        }

        // Trying to make the functions recursive :))
        Node* deleteTreeNode(Node* ptr, int val){
            if(ptr == nullptr){
                return ptr;
            }
            if(ptr->val < val){
                ptr->right = deleteTreeNode(ptr->right, val);
            }
            else if (val < ptr->val){
                ptr->left = deleteTreeNode(ptr->left, val);
            }
            else{
                if(ptr->right == nullptr){
                    Node* temp = ptr->left;
                    delete ptr;
                    return temp;
                }
                if(ptr->left == nullptr){
                    Node* temp = ptr->right;
                    delete ptr;
                    return temp;
                }

                Node* temp = getInorderSuccessor(ptr);
                ptr->val = temp->val;
                ptr->right = deleteTreeNode(ptr->right, temp->val);
            }
            return ptr;
        }

    public: 
        // BST initialized with val as the root node's value.
        BST(int val){
            this->root = new Node(val);
        }

        // BST initialized with no root node's value.
        BST(){
            this->root = nullptr;
        }

        void insert(int val){
            this-> root = insertNode(this->root, val);
        }

        void preOrder(){
            preOrderTraverse(this->root);
            cout << "\n";
        }

        void inOrder(){
            inOrderTraverse(this->root);
            cout << "\n";
        }
        
        void postOrder(){
            postOrderTraverse(this->root);
            cout << "\n";
        }

        Node* search(int val){
            return searchTree(this->root, val);
        }

        void deleteNode(int val){
            this->root = deleteTreeNode(this->root, val);
        }

};



int main(){
    
    int n;
    cin >> n;
    int x;
    BST bst;

    for(int i = 0; i < n; i++){
        cin >> x; bst.insert(x);
    }
    
    bst.preOrder();
    bst.inOrder();
    bst.postOrder();

    cout << "Enter the value to be searched : ";
    cin >> x;
    Node* ptr = bst.search(x);
    
    cout << ((ptr == nullptr) ? "The valus is not found in BST " : "The value is found in the BST at ") << ptr;

    cout << "\nEnter the value to delete : "; cin >> x;
    bst.deleteNode(x);
    
    cout << "Deleted " << x << " from the BST\n";
    cout << "Tree after deletion is :\n";
    bst.preOrder();
    bst.inOrder();
    bst.postOrder();

}

