#include<iostream>
#include<vector>


using namespace std;

//This code do need some test case passing, so I will get back to it later!!

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int countOfZeros = 0;

        int max = 0;
        int curr = 0;
        int i = 0, j = 0;
        while(j < n){

            if(nums[j] == 1){
                j++;
            } else if (countOfZeros < k) {
                j++; countOfZeros++;
            } else if(nums[i] == 1) {
                i++;
            } else {
                i++; countOfZeros--;
            }
            curr = j - i;
            if(curr > max) max = curr;
        }
        return max;
    }
};

int main(){

    int n, k;
    Solution sol;
    cin >> n >> k;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << sol.longestOnes(nums, k);

}
