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

// Our Code starts from here:

template<typename T>
class linkedliststack{
    private:
        int size = 0;
        linked_list<T> list;
        int maxSize;

    public:
        linkedliststack<T>(int n): maxSize(n){}
        linkedliststack<T>(): maxSize(1000){} // Default maximum size of the linked list.
        
        void push(T data){
            if(maxSize == size){
                cout<< "Stack Overflow.\n";
                return;
            }
            list.push_back(data);
            size++;
        }
        T pop(){
            if(size == 0){
                cout<< "Stack Underflow.\n";
                return NULL;
            }
            size--;
            return list.pop_back();
        }

        int getSize(){
            return size;
        }
        int getMaxSize(){
            return maxSize;
        }
        void print(){
            list.print();return;
        }

};

int main(){

    linkedliststack<string> s;
    s.push("Hello");
    s.push("World");
    s.push("I");
    s.push("am");
    s.push("Piyush");
    s.push("Singh");
    s.push("Bhati");
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
}

