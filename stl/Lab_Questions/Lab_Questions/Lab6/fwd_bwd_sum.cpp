/*
You are given two sequences A and B consisting of N integers. You may choose any index i (1 < i < n) and simultaneously apply the following changes:

Ai-1 := Ai-1 + Ai
Ai := -Ai
Ai+1 := Ai+1 + Ai

Determine whether you can make array A equal to array B after applying this operation any number of times (possibly zero).

Input

The first line of each test case contains a single integer N --- the number of integers in each sequence.

The second line of each test case contains N integers A1, A2, ..., An.

The third line of each test case contains N integers B1, B2, ..., Bn.

Output

Output "Yes" (without quotes) if B can be obtained by applying the aforementioned operation on A any number of times, and "No" (without quotes) otherwise.

Sample Input

4
3 2 -2 -3
3 0 2 -5

Sample Output

Yes

Explanation

We can obtain the array [3,0,2,-5] by applying the operation one time on index i=3.
*/

//Solution:
#include <iostream>
using namespace std;


bool isSame(int *A, int *B, int N){
    for(int i = 0; i < N; i++)
        if(A[i] != B[i])
            return false;
    return true;
}


int main() {
    int N;
    
    int A[N], B[N];
    
    for(int i = 0; i < N; i++) cin>> A[i];
    for(int i = 0; i < N; i++) cin>> B[i];
    int mul = 1;
    
    for(int i = 0; i < N; i++){
        
        if(i == 0){
            if(A[i] == -B[i]){
                A[i] = -A[i];
            }
            if((B[i] - A[i]) % A[i + 1] == 0 && A[i + 1] != 0){
                mul = (B[i] - A[i]) / A[i + 1];
                A[i] = A[i] + mul * A
            }
            
        }
        if(i != 0 && i!= N - 1){
            if(A[i] == -B[i]){
                A[i] = -B[i];
            }
            
        }
        if(i == N - 1){
            if(A[i] == -B[i]){
                A[i] = -B[i];
            }
            
        }
    }
    
}