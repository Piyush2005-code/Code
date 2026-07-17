#include<iostream>


using namespace std;


class Stack{
    private:
        int *arr;
        int cap;
        int size;

    public:
        Stack(int _cap): cap(_cap), size(0){
            arr = new int[_cap];
        }

        int push(int x){
            if(size >= cap) return 1;
            arr[size++] = x;
            return 0;
        }

        int top(){
            return arr[size - 1];
        }

        int stackSize(){
            return this->size;
        }

        int pop(){
            if(size > 0){
                size--;
                return 0;
            }
            return 1;
        }

        void printStack(){
            cout << endl;
            for(int i = 0; i < size; i++){
                cout << arr[i] << " ";
            }
        }
};


int main(){
    
    int n;
    cin >> n;

    Stack stk = Stack(n);

    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        stk.push(x);
    }

    stk.printStack();
    // cout << stk.top();
    stk.pop();
    stk.push(3);
    stk.printStack();
    // cout << stk.top();
    stk.pop();
    stk.printStack();

}
