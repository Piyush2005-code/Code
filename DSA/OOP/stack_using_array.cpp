#include<iostream>
#include<string>


using namespace std;

class Stack{
    protected:
        int t;
        int n;
        int arr[];
    public:
        Stack(int max_elements): n(max_elements){
            int arr[n]; t = -1;
        }
        
        void push(int x){
            arr[++t] = x;
        }

        int pop(){
            if(t < 0){
                cout<< "\nStack empty.";
                return -1;
            }
            else{
                return arr[t--];
            }
        }

        int peek(){
            if(t < 0){
                cout<< "\nStack empty."; return -1;
            }
            else{
                return arr[t];
            }
        }

        int getMaxSize(){
            return n;
        }
        
        int getSize(){
            if(t < 0){
                cout<< "\nStack empty.";
                return -1;
            }
            else{
                return t + 1;
            }
        }

        int getValue(int i){
            return arr[i];
        }
};


int main(){

    Stack nums = Stack(100);

    cout<< "\nMax Size of Stack: "<< nums.getMaxSize();
    nums.push(2);
    nums.push(3);
    nums.push(4);

    cout<< "\nPeeking into the stack: "<< nums.peek();
    int popped_value = nums.pop();
    cout<< "\nPopped value of the stack: "<< popped_value;
    cout<< "\nNow peeking after popping the top value: "<< nums.peek();
    cout<< "\nAgain popping a value: "<< nums.pop();
    cout<< "\nAgain peeking into the stack: "<< nums.peek();
    cout<< "\n\nCurrent size of the stack: "<< nums.getSize();
    cout<< endl<< nums.getValue(101); // Gives a segmentation fault.

}


