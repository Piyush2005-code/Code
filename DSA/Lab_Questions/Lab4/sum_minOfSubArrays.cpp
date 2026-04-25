/*
Given an array of integers arr, find the sum of minimums of all possible contiguous subarrays of arr. Since the answer may be large, return the answer modulo 10^9 + 7.

Example: arr = [3,1,2,4]
Answer: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2 : arr = [11,81,94,43,3]
Answer: 444

Input format:
1st line contains integer n, size off arr
next line contains n integers, representing elements of arr.

Output format:
a single integer (the sum) mod 10^9+7

Complete the class definition of Stack data Structure and the function to compute the sum of all minima.
*/

//Solution:
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

class Stack{
    int top;
    vector<int> v;
    int maxSize;

public:

    Stack(int size){
        v = vector<int>(size,0);
        maxSize = size;
        top = -1;
    }

    bool isEmpty(){
        return // single boolean expression : when is the stack empty? //
    }

    bool isFull(){
        return (top == size - 1): true? false;
    }

    int peek(){
        // return the element at the top
    }

    int pop(){
        if(isEmpty()) cerr << "Popping from empty stack";
        else{
            int top_ele = v[top];
            v[top--] = 0;
            return top_ele;
        }
        // remomove the top element and return it
    }

    void push(int x){
        if(isFull()) cerr << "Pushing into a full stack";
        v[++top] = x;
    }

    void printWholeStack(){
        for(int i=top;i>=0;i--) cout << v[i] <<" ";
        cout<<'\n';
    }

};

ll sum_minOfSubArrays(vector<ll>& v){
    int n = v.size();

    // Complete the function now

}

int main() {

    int n; cin >> n;
    vector<ll> v(n,0); for(int i=0;i<n;i++) cin >> v[i];

    cout << sum_minOfSubArrays(v);

    return 0;
}