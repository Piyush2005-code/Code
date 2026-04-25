/*
You are given a stack of N integers such that the leftmost element is on the top and the rightmost element is at the bottom of the stack.
In one operation, you can either pop an element from the stack or push any popped element into the stack. You need to maximize the top element of the stack after performing exactly K operations. If the stack becomes empty after performing K operations and there is no other way for the stack to be non-empty, print -1.

Input format:
The first line of input consists of two space-separated integers N and K.
The second line of input consists N space-separated integers denoting the elements of the stack. The first element represents the top of the stack and the last element represents the bottom of the stack.
Output format :
Print the maximum possible top element of the stack after performing exactly K operations.

Sample test case:
Input:
6 4
1 2 4 3 3 5
Output : 4
*/

//Solution:
#include <bits/stdc++.h>
using namespace std;

#define elif else if
#define print(s) cout<<(s)<<endl
#define ll long long

class stack{
    // complete the methods and define the required variables 
    void push(ll val){
        
    }
    void pop(){
        
    }
    ll top(){
        
    }
    ll size(){
        
    }
    bool empty(){
        
    }
};

int main(){
    // Answer Variable
    ll mx = -1e9;

    
    // take n and k as input
    
    // take input elements and push them in stack
    // remember the leftmost elem should be at the top so you need to push them in reverse order

    // handle base cases

    // write the main solution code


    // OUTPUT
    print(mx);
    return 0;
}