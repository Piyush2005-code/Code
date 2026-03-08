#include<iostream>

using namespace std;

class Solution {
public:
    int dp(int n, int memoize[]){
        if(n <= 0){
            return 0;
        }
        else if(n == 1){
            return 1;
        }
        else if(n == 2){
            return 2;
        }
        else{
            if(memoize[n] != 0)
                return memoize[n];
            else{
                if(!memoize[n - 1]) memoize[n - 1] = dp(n - 1, memoize);
                if(!memoize[n - 2]) memoize[n - 2] = dp(n - 2, memoize);
                return memoize[n - 1] + memoize[n - 2];
            }
        }
    }

    int climbStairs(int n) {
        int memoize[n + 1];
        for(int i = 0; i < n + 1; i++){
            memoize[i] = 0;
        }
        return dp(n, memoize);
    }
};


int main(){
    int n;
    cin >> n;
    Solution sol;
    cout<< sol.climbStairs(n);

}