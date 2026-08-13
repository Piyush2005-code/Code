#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    
    // Well This is the brute force solution...
    bool solve(vector<int>& nums, int i, int sum, int target){
        if(sum == target) return true;
        if(i >= nums.size() || sum > target) return false;
        return solve(nums, i + 1, sum + nums[i], target - nums[i]) || solve(nums, i + 1, sum, target);
    }

    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(int i = 0; i < nums.size(); i++) target += nums[i];
        if(target % 2) return false;
        target /= 2;
        vector<vector<bool>> dp = vector<vector<bool>>(nums.size(), vector<bool>(target + 1, 0));

        for(int i = 0; i < nums.size(); i++) dp[i][0] = true;
        if(nums[0] <= target)
            dp[0][nums[0]] = true;
        for(int ind = 1; ind < nums.size(); ind++){
            for(int k = 0; k <= target; k++){
                bool notTake = dp[ind - 1][k];
                bool take = false;
                if(nums[ind] <= k) take = dp[ind - 1][k - nums[ind]];
                dp[ind][k] = take || notTake;
            }
        }

        return dp[nums.size() - 1][target];
    }
};

