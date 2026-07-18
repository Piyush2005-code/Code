#include<iostream>
#define MAX_CHAR 26


using namespace std;


class Node{
    public:
        Node* children[MAX_CHAR];
        bool isLeaf;

        Node(){
            for(int i = 0; i < MAX_CHAR; i++) children[i] = nullptr;
            isLeaf = false;
        }
};


class Trie{
    private:
        Node* root;

        void printRec(Node* root, string s){
            if(root->isLeaf){
                cout << s << endl;
                return;
            }
            for(int i = 0; i < MAX_CHAR; i++){
                if(root->children[i]){
                    char c = 'a' + i;
                    printRec(root->children[i], s + c);
                }
            }
        }

        void deleteNodes(Node* root){
            for(int i = 0; i < MAX_CHAR; i++){
                if(root->children[i]) deleteNodes(root->children[i]);
            }
            delete root;
        }


    public:

        Trie(){
            root = new Node();
        }

        ~Trie(){
            deleteNodes(this->root);
        }

        bool search(string s){
            Node* curr = this->root;

            for(const char &c : s){
                int i = c - 'a';
                if(!curr->children[i]) return false;
                curr = curr->children[i];
            }
            return curr->isLeaf; // Here the return statement is curr->isLeaf, which means the exact word should be present, not as a prefix.
        }


        void insert(string s){
            if(root == nullptr) root = new Node();
            Node* curr = root;

            for(const char& c : s){
                int i = c - 'a';

                if(!curr->children[i]){
                    curr->children[i] = new Node();
                }
                if(curr->isLeaf) curr->isLeaf = false;
                curr = curr->children[i];
            }

            curr->isLeaf = true;
        }


        bool isPrefix(string s){
            Node* curr = this->root;

            for(const char& c : s){
                int i = c - 'a';
                if(!curr->children[i]) return false;
                curr = curr->children[i];
            }

            return true;
        }


        void printTrieWords(){
            cout << endl;
            string s;
            for(int i = 0; i < MAX_CHAR; i++){
                if(this->root->children[i]){
                    char c = 'a' + i;
                    s = "";
                    printRec(root->children[i], s + c);
                }
            }
        }
};


int main(){

    int n;
    cout << "Enter the number of strings to input : \n";
    cin >> n;
    string s;
    Trie trie;

    for(int i = 0; i < n; i++){
        cin >> s;
        trie.insert(s);
    }

    trie.printTrieWords();

}
