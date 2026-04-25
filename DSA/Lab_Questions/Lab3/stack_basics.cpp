/*
Write a program to perform the basic operations of a stack such as push(), pop(), peek(), isFull(), isEmpty(). Assume stack is of size 100 integers. The program should take input of a given n number of integers and push them into the stack and then perform the operations in the order mentioned below.
Input Format:
	N 1, 2, 3, ..n integers
Output Format:
	Output of peek(), printWholeStack(), pop(), isFull(), and isEmpty() in a new line:
Example:
	Input : 5 15 123 62 10 44
	Output: 
		44
		44 10 62 123 15 5
		44
		0 // isFull() returns 1 if full, 0 otherwise
		0 // isEmpty() returns 1 if empty, 0 otherwise
    
*/

//Solution Template:

// #include <iostream>

// using namespace std;

// #define MX_SIZE 1000

// class Stack{
//     int top = -1;
//     int v[MX_SIZE];

// public:
    
//     /* Check if the stack is empty */
//     int isEmpty(){
//     // ADD YOUR CODE
//     }

//     /* Check if the stack is full */
//     int isFull(){
//     //ADD YOUR CODE
//     }

//     /* Function to return the topmost element in the stack */
//     int peek(){
//     //ADD YOUR CODE
//     }

//     /* Function to delete from the stack */
//     int pop(){
//     //ADD YOUR CODE
//     }

//     /* Function to insert into the stack */
//     int push(int data){
//     //ADD YOUR CODE
//     }

//     void printWholeStack(){
//         for(int i=0;i<=top;i++){
//             cout<<v[i]<<" ";
//         }
//         cout<<endl;
//     }

// };

// /* Main function */
// int main(){
   
//    int n,x,i;
//    cin>>n;
//    Stack s;
//    for(i=0;i<n;i++){
//         cin>>x;
//         s.push(x);
//    }
//    x=s.peek();
//    cout<<x<<endl;
//    s.printWholeStack();
//    x=s.pop();
//    cout<<x<<endl;
//    cout<<s.isFull()<<endl;
//    cout<<s.isEmpty()<<endl;
//    return 0;
// }


//Solution:

#include<iostream>

using namespace std;

#define MAX_SIZE 100

class Stack{
    private:
        int top = -1;
        int arr[MAX_SIZE];
    public:

        Stack(): top(-1){}

        int push(int x){
            if(top < MAX_SIZE - 1){
                arr[++top] = x;
                return 1;
            }
            else{
                return 0;
            }
        }

        int pop(){
            if(!this->isEmpty()){
                int x = arr[top];
                top--;
                return x;
            }
            else{
                cout<< "Stack underflow\n";
                return INT_MIN;
            }
        }

        int peek(){
            if(!this->isEmpty()){
                return arr[top];
            }
            else{
                cout<< "Stack empty.\n";
                return INT_MIN;
            }
        }

        int isEmpty(){
            if(top < 0) return 1;
            else return 0;
        }

        int isFull(){
            if(top == MAX_SIZE - 1) return 1;
            else return 0;
        }

        int printWholeStack(){
            if(top > -1){
                int i = top;
                while(i + 1){
                    cout<< arr[i]<< " ";
                    i--;
                }
                cout<< endl;
                return 1;
            }
            else{
                return 0;
            }
        }
};



int main(){

    Stack stc;

    int n, x;
    cin>> n;

    for(int i = 0; i < n; i++){
        cin>> x;
        stc.push(x);
    }
    cout<< stc.peek()<< endl;
    stc.printWholeStack();
    cout<< stc.pop()<< endl;
    cout<< stc.isEmpty()<< endl;
    cout<< stc.isFull()<< endl;
}

//Solved.