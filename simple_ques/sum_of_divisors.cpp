#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int returnSum = 0;
        int n = nums.size();
        int currentSum;
        int number_of_divisors;

        for(int i = 0; i < n; i++){
            currentSum = 0;
            number_of_divisors = 0;
            for(int j = 1; j <= nums[i]; j++){
                if (nums[i] % j == 0){
                    number_of_divisors++; currentSum += j;
                }
            }
            if(number_of_divisors == 4) returnSum += currentSum;
        }
        return returnSum;
    }
};



int main(){

    int n;
    cin>> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) cin>> arr[i];

    Solution sol;
    cout<< sol.sumFourDivisors(arr);

}