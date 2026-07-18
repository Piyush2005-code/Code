#include<iostream>


using namespace std;


class Node{
    public:
        int val;
        Node* next;
   
        Node(int _val) : val(_val), next(nullptr){}     
        // Node(int _val, Node* _next) : val(_val), next(_next){}
};


class Stack{
    private:
        Node* head;
        int cap;
        int size;

    public:
        Stack(int _cap) : cap(_cap), size(0) {
            this->head = nullptr;
        }


        void push(int _val){
            if(size >= cap) {
                cout << "Stack Overflow! cannot push " << _val << " onto the stack\n";
                return;
            }
            // Inefficient implementation earlier when I used two pointers of head and tail.
            // if(this->head == nullptr){
            //     this->head = new Node(_val);
            //     cout << "Pushed the first element " << _val << " into the stack\n";
            //     size++;
            //     return;
            // }
            //
            // Node* curr = new Node(_val);
            // curr->next = this->head;
            // this->head = curr;
            // size++;
            // cout << "Pushed the element " << _val << " into the stack";
            // return;

            Node* temp = new Node(_val);
            if(this->head == nullptr){
                this->head = temp;
                this->size++;
            } else {
                temp->next = this->head;
                this->head = temp;
                this->size++;
            }
            cout << "Pushed " << _val << " into the top of the stack.\n";
        }


        int getSize(){
            return size;
        }


        int top(){
            if(head) return head->val;
            cout << "Stack empty\n";
            return -1;
        }


        void pop(){
            if(this->size == 0){
                cout << "Stack Underflow!\n";
                return;
            }
            Node* temp = head;
            head = head->next;
            size--;
            cout << "Removed " << temp->val << " from the top of the stack";
            delete temp;
            return;
        }

        void printStack(){
            Node* curr = this->head;
            cout << "The elements of the stack are:\n";
            while(curr){
                cout << curr->val << endl;
                curr = curr->next;
            }
            cout << "-----End of the Stack-----\n" << endl;
        }

};


void StackTest(Stack& st){
    string s;
    int x;

    while(1){
        cin >> s;
        if(s == "push"){
            cin >> x;
            st.push(x);
            cout << endl;
        }
        if(s == "top"){
            cout << st.top() << endl;
        }
        if(s == "pop"){
            st.pop(); cout << endl;
        }
        if(s == "getSize"){
            cout << st.getSize() << endl;
        }
        if(s == "print"){
            st.printStack();
        }
        if(s == "exit"){
            break;
        }
    }
}


int main(){

    int n;
    cout << "\nEnter the capacity of the Stack : ";
    cin >> n;
    Stack stk(n);

    cout << "\n-------Interactive stack testing-------\n";

    StackTest(stk);

}
