#include<iostream>
#include<string>

using namespace std;

template<typename T>
class Node{
    public:
        T data;
        Node<T>* next;

        Node<T>(T data){
            this->data = data;
            this->next = NULL;
        }
        Node<T>(){
            this->next = NULL;
        }

};


template<typename T>
class linked_list{
    private:
        Node<T>* head = NULL;

    public:
        void push_back(T data){
            Node<T>* newNode = new Node<T>(data);
            if(head == NULL) this->head = newNode;
            else if(head->next == NULL) head->next = newNode;
            else{
                Node<T>* ptr = head;
                while(ptr->next != NULL) ptr = ptr->next;
                ptr->next = newNode;
            }
        }

        void push_front(T data){
            Node<T>* newNode = new Node<T>(data);
            if(head == NULL) head = newNode;
            else{
                newNode->next = head;
                head = newNode;
            }
        }

        T pop_front(){
            T data;
            if(head == NULL){
                cout<< "The list is empty.\n";
                return NULL;
            }
            else{
                data = head->data;
                Node<T>* ptr = head;
                head = head->next;
                delete ptr; return data;
            }

        }


        T pop_back(){
            Node<T>* ptr = head;
            if(head == NULL){
                cout<<"The list is empty!\n";
                return NULL;
            }
            else if(head->next == NULL){
                T data = head->data;
                delete head;
                head = NULL;
                return data;
            }
            else{
                while(ptr->next->next != NULL) ptr = ptr->next;
                T data = ptr->next->data;
                delete ptr->next;
                ptr->next = NULL;
                return data;
            }
        }
        void print(){
            Node<T>* ptr = head;
            if(head == NULL) cout<< "The list is empty.\n";
            else{
                while(ptr->next != NULL){
                    cout<< ptr->data<< " ";
                    ptr = ptr->next;
                }cout<< ptr->data;
                cout<< endl;
            }
        }


};



int main(){

    linked_list<string> list;
    list.push_back("Hello");
    list.push_back("World");
    list.push_back(",");
    list.push_back("I");
    list.push_front("am");
    list.push_front("Piyush");
    list.push_front("Singh");
    list.push_front("Bhati");
    list.print();
    list.pop_back();
    list.pop_back();
    list.pop_back();
    list.pop_back();
    list.pop_back();
    list.print();
    list.pop_front();
    list.print();
    list.pop_front();
    list.print();
}