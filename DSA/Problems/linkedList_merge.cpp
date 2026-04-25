#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data): data(data), next(NULL) {}
    Node(int data, Node* next): data(data), next(next) {}

};

class LinkedList{
    public:
    Node* head = NULL; // Very important step, without it the first push_back() wouldn't work.

    void push_back(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
        }
        else{
            Node* ptr = head;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
    }

    void print(){
        Node* ptr = this->head;
        while(ptr != NULL){
            cout<< ptr->data<< " ";
            ptr = ptr->next;
        }
        if(head == NULL) cout<< "The List is empty.";
        cout<< endl;
    }    
    
};    

LinkedList mergelists(vector<Node*> &headArr){
    int k = headArr.size();
    int key = 1;
    // cout<< headArr[0]->data;
    LinkedList list;

    while(key){
        int sumofnull = 0;
        int min_idx = 0;
        for(int i = 0; i < k; i++){
            cout<< "ok";
            if(headArr[i] == NULL){
                sumofnull++;
            }
            else if(headArr[min_idx]->data > headArr[i]->data){
                min_idx = i;
            }
            cout<< "ok";
        }
        int x = headArr[min_idx]->data;
        list.push_back(x);
        headArr[min_idx] = headArr[min_idx]->next;

        if(sumofnull == k) break;

    }
    return list;

}


int main(){
    
    
    int n; 
    cin>> n;
    LinkedList arr[n];
    
    for(int i = 0; i < n; i++){
        int m;
        cin>> m;
        for(int j = 0; j < m; j++){
            int x; cin>> x;
            arr[i].push_back(x);
        }    
    }    
    


    
}    

// Solution is not working.