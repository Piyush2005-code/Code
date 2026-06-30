#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    int max(int a, int b){
        return (a > b)? a: b;
    }

    int size(int x){
        int n = 0;
        while(x){
            x /= 2;
            n++;
        }
        return n;
    }

    // Inplace filling of the Binary Array;
    void fillBinaryArr(vector<int> &arr, int x, int n){
        int i = n - 1;
        while(x && i >= 0){
            arr[i] = x % 2;
            x /= 2;
            i--;
        }
    }

    int carryOfAdder(int A, int B, int Cin){
        return ( Cin & ( A | B ) | (A & B));
    }

    int sumOfAdder(int A, int B, int Cin){
        return (A ^ B ^ Cin);
    }

    void sumTwoArr(vector<int> &res, vector<int> &arrA, vector<int> &arrB, int n){
        int i = n - 1;
        int C = 0;
        while(i >= 0){
            res[i + 1] = sumOfAdder(arrA[i], arrB[i], C);
            C = carryOfAdder(arrA[i], arrB[i], C);
            i--;
        }
        res[i + 1] = sumOfAdder(arrA[i], arrB[i], C);
    }

    int getResult(vector<int> &arr, int n){
        int sum = 0;
        int i = 0;
        while(i < n){
            int x = 0;
            if(arr[i] == 1){
                x = arr[i];
                cout<< x << " doubling... ";
                for(int j = 0; j < (n - 1) - i; j++)
                    x *= 2;
                cout<< x<< endl;
            }
            sum = sum | x;
            cout<< "Sum: "<< sum<< endl;
            i++;
        }
        return sum;
    }
    void printArr(vector<int> arr){
        for(auto x: arr)
            cout<< x<< " ";
        cout<< endl;
    }

    int getSum(int a, int b) {
        int n = max(size(a), size(b));

        vector<int> arrA(n, 0);
        vector<int> arrB(n, 0);
        vector<int> res(n + 1, 0);

        fillBinaryArr(arrA, a, n);
        printArr(arrA);
        fillBinaryArr(arrB, b, n);
        printArr(arrB);
        sumTwoArr(res, arrA, arrB, n);
        printArr(res);
        
        int result = getResult(res, n + 1);
        return result;
    }
};



int main(){

    int a, b;
    cin >> a >> b;
    Solution sol;
    
    cout<< sol.getSum(a, b);

}