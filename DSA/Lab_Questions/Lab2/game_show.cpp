/*
Julian is running a game show, but people's interest has been declining. To make the game show exciting, he decides to "fix" the results and write a good script for the show to make it more entertaining. The format of the show is as follows:
There are 2 contestants, each of which get to either get the next reward or pass to the other contestant. Once passed, the chance to get rewards does not revert to the contestant until the other contestant passes his/her reward. (Both cannot simultaneously pass a reward). Each reward can be positive, negative or zero integer.

Julian wants to fix the rewards, such that there are "exactly" 2 "passes", and the game ends in a tie. Can you help Julian determine if a given sequence of rewards is "fixable"?

Input:
Number of questions in the round "n"
The points scored for the reward

Output:
Number of ways to fix the round. 

E.g.1:
Input - 
6
-16 1 5 -6 7 9
Output - 
1

E.g.2:
Input - 
5
1 5 -6 7 9
Output - 
0

Explanation i) The possible sets of passes include {2,5}, which makes each contestants total -16 + 7 + 9 = 1 + 5 + (-6) = 0 
ii) No way to tie up the scores in 2 passes (possible with 3 passes, {2,4,5}, but not 2)

(Hint: Similar to finding 1 pass division)*/

//Solution Template:




//Solution:
#include<iostream>

using namespace std;

class LinkedList{
    public:
        class Node{
            public:
                int data;
                Node* next;
                
                Node(int data){
                    this->data = data;
                    this->next = NULL;
                }
            
        };
        int size;
        Node *root;
        
        LinkedList(){
            this->root = NULL;
            this->size = 0;
        }
        
        // ~LinkedList() {
        //     Node* ptr = this->root;
        //     Node* del_ptr = ptr;
        //     while(ptr != NULL){
        //         del_ptr = ptr;
        //         ptr = ptr->next;
        //         delete del_ptr;
        //     }
        //     delete this;
        // }
        
        void push(int value){
            Node* newNode = new Node(value);
            if(this->root == NULL){
                this->root = newNode; size++;
            }
            else{
                Node* ptr = root;
                while(ptr->next != NULL) ptr = ptr->next;
                ptr->next = newNode; size++;
            }
        }
        
        int sum(){
            int sum = 0;
            Node* curr = this->root;
            while(curr){
                sum += curr->data;
                curr = curr->next;
            }
            return sum;
        }
        
        int at(int i){
            if(i >= this->size){
                cout<< "The index is out of bounds.\n";
                return -9999;
            }
            else{
                Node* curr = this->root;
                for(int l = 0; l < i; l++) curr = curr->next;
                return curr->data;
            }
        }
        
        int subSum(int i, int j){
            int sum = 0;
            if(i >= size || j > size){cout<< "The index is out of bounds.\n";return -9999;}
            for(int l = i; l <= j; l++){
                sum += this->at(l);
            }
            return sum;
        }
        
        void print(){
            if(root==NULL) cout<< "The list is empty.\n";
            else{
                Node* curr = root;
                while(curr){
                    cout<< curr->data<< " ";
                    curr = curr->next;
                }
            }
        }
        
        int solution(){
            int Sum = this->sum();
            int fixable = 0;
            for(int i = 0; i < size-2; i++){
                for(int j = i + 1; j < size-1; j++){
                    if(Sum == fixable)
                        fixable++;
                }
            }
            return fixable;
        }
        
};

int main(){
    LinkedList L;
    int size;
    int x;
    cin>> size;
    for(int i = 0; i < size; i++){
        cin>> x;
        L.push(x);
    }
    // L.print();
    cout << L.solution();
    
    return 0;
}