/*
Given an expression string, write a program to examine whether the pairs and the orders of “{“, “}”, “(“, “)”, “[“, “]” are correct in the given expression using a stack. Output 1 if expression is balanced, 0 if not.

Input : “[()]{}{[()()]()}” 
Output: 1

Input : “[()]{}{[()()()}” 
Output: 0

Constraints:
1 <= 'N' <= 10^3

Where 'N' is the length of the input string.
*/

//Solution:
#include <bits/stdc++.h>
using namespace std;

class Stack {
    private:
        char arr[1000];
        int top = -1;
    public:
        void push(char c){
            if(top < 999){
                arr[++top] = c;
            }
            else{
                cout<< "Stack overflow.";
            }
        }
        
        char peek(){
            if(top > -1){
                return arr[top];
            }
            else{
                return '\0';
            }
        }
        
        char pop(){
            if(top > -1){
                char c = arr[top]
                top--;
                return c;
            }
            else return '\0';
        }
        
        bool isEmpty(){
            if(top < 0) return 1;
            else return 0;
        }
    
};

bool isValid(string s) {
    int size = s.size();
    int len = 0;
    Stack stk;
    for(int i = 0; i < size; i++){
        if(!stk.isEmpty()){
            if(stk.peek() == '(' && s[i] == ')'){
                stk.pop(); len++;
            }
            if(stk.peek() == ')' && s[i] == '('){
                


        }
    }
    
}

int main() {
    // Do not change this.
    string s;

    cin>>s;

    // Check if parentheses are valid and print 1 or 0
    std::cout << (isValid(s) ? 1 : 0) << std::endl;

    return 0;
}