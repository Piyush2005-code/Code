#include<iostream>
#include<vector>


using namespace std;

class Solution {
private:
    int maxMoney(vector<int>& nums, int i, vector<int>& dp){
        if(i == nums.size() - 1) return nums[i];
        if(dp[i] != -1) return dp[i];
        int max_money = nums[i];
        if(i + 2 < nums.size()) max_money += maxMoney(nums, i + 2, dp);
        for(int j = i + 3; j < nums.size(); j++){
            int x = nums[i] + maxMoney(nums, j, dp);
            if(max_money < x) max_money = x;
        }
        dp[i] = max_money;
        return dp[i];
    }   

public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int max_money = maxMoney(nums, 0, dp);
        for(int i = 1; i < nums.size(); i++){
            if(max_money < maxMoney(nums, i, dp)) max_money = maxMoney(nums, i, dp);
        }
        return max_money;
    }
};


int main(){
    int n; 
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    Solution sol;
    cout << sol.rob(nums);
}
