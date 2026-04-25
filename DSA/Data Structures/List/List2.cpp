#include<iostream>
#include<string>

using namespace std;

template<typename T1>
class Node{
    public:
        T1 data;
        Node<T1>* next = NULL;


        Node(){ 
            next = NULL;
        }

        Node(T1 data){
            this->data = data;
            this->next = NULL;
        }

        void setValue(T1 data){
            this->data = data;
        }
        void setNext(Node* next){
            this->next = next;
        }
};


template<typename T1>
class linkedList{
    private:
        Node<T1>* head = NULL;
        int size = 0;

    public:
    void push_back(T1 data){
        if(head == NULL){
            this->head = new Node<T1>(data);
            cout<< "\nFirst Data memeber inserted.";
        }
        else{
            Node<T1>* ptr = head;
            while(ptr != NULL){
                ptr = ptr->next;
            }
            ptr = new Node<T1>(data);
            cout<< "\nData member Inserted.";
        }
        size++;
    }
    
    void print(){
        Node<T1>* ptr = head;
        if(ptr == NULL)
            cout<< "\nList is empty.";
        else{
            cout<< endl;
            while(ptr != NULL){
                cout<< ptr->data<< " ";
                ptr = ptr->next;
            }
        }
    }

    void print(int i){
        Node<T1>* ptr = head;
        int j = 0;
        while(j != i){
            ptr = ptr->next;
            j++;
        }
        cout<< ptr->data;
    }

    int getSize(){
        return this->size;
    }

    Node<T1>* front(){
        return head;
    }

    Node<T1>* back(){
        if(head == NULL || head->next == NULL)
            return head;
        else{
            Node<T1>* ptr = head;
            while(ptr->next != NULL)
                ptr = ptr->next;
            return ptr;
        }
    }

    int push_front(T1 data){
        Node<T1>* ptr = new Node<T1>(data);
        ptr->next = this->head;
        this->head = ptr;
        return 1;
    }

    T1 pop_back(){
        Node<T1>* ptr = head;
        T1 value;
        if(head == NULL){
            cout<< "\nList is empty";
            return NULL;
        }
        else if(head->next == NULL){
            value = head->data;
            delete head;
            head = NULL;
            return value;
        }
        else{
            while(!(ptr->next->next== NULL)){
                ptr = ptr->next;
            }
            value = ptr->next->data;
            delete ptr->next;
            ptr->next = NULL;
            return value;
        }
    }
};


int main(){
    linkedList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    list.print();
    int n = list.getSize();
    for(int i = 0; i < n; i++){
        list.print(i);
        cout<< endl;
    }
    cout<< endl;
}

