#include<iostream>
#include<string>


using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = nullptr;
        }
        
        Node(){
            data = 0;
            next = nullptr;
        }
};

class linked_list{

    protected:
        Node* head;

    public:
        linked_list(){
            head = nullptr;
        }

        void push_back(int data){
            // //  The below method is working now:
            // if(head == nullptr){
            //     head = new Node(data);
            // }
            // else if(head->next == nullptr){
            //     head->next = new Node(data);
            // }
            // else{
            //     Node* ptr = head;
            //     while(ptr->next != nullptr)
            //         ptr = ptr->next;
            //     ptr->next = new Node(data);

            // }

            // I am implementing a second method here below:
            Node* newNode = new Node(data);
            if(head == NULL) head = newNode;
            else if(head->next == NULL) head->next = newNode;
            else{
                Node* ptr = head;
                while(ptr->next != NULL) ptr = ptr->next;
                ptr->next = newNode;
            }
        }

        void push_front(int data){
            Node* newNode = new Node(data);
            if(head == NULL) head = newNode;
            else{
                newNode->next = head;
                head = newNode;
            }
        }

        void print(){
            if(head == nullptr){
                cout<< "\nThe List is empty.";
            }
            else{
                Node* ptr = head;
                cout<< endl;
                while(ptr != nullptr){
                    cout<< ptr->data<< " ";
                    ptr = ptr->next;
                }
                
            }

        }

        //The method returns 0 if the insertion didn't take place.
        int insert_between(int data, int left, int right){
            Node* newNode = new Node(data);
            if(head == NULL){
                cout<< "\nThe list is empty.";
                return 0;
            }
            else if(head->next == NULL){
                cout<< "\nThe list does not have enough elements.";
                return 0;
            }
            else{
                Node* newNode = new Node(data);
                Node* leftNode = head;
                Node* rightNode = head->next;
                while((leftNode->data != left || rightNode->data != right) && rightNode != NULL){
                    leftNode = leftNode->next;
                    rightNode = rightNode->next;
                }
                if(rightNode == NULL){
                    cout<< endl<< "No such elements as "<< left<< " and "<< right<< " are present in the List.";
                    return 0;
                }
                else{
                    leftNode->next = newNode;
                    newNode->next = rightNode;
                    return 1;
                }
            }
        }

};

int main(){

    linked_list list;
    list.push_front(-2);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.insert_between(5, 2, 3);
    list.push_back(4);
    list.push_back(5);
    list.push_front(0);
    list.push_front(-1);
    list.print();
}