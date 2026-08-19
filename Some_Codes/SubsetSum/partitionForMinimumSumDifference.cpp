#include<iostream>
#include<vector>


using namespace std;


class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        // int target = accumulate(nums.begin(), nums.end(), 0);
        int target = 0;
        for(int i = 0; i < n; i++) target += nums[i];
        vector<vector<bool>> dp = vector<vector<bool>>(n, vector<bool>(target + 1, false));

        for(int i = 0; i < n; i++) dp[i][0] = true;
        if(nums[0] <= target) dp[0][nums[0]] = true;

        for(int ind = 1; ind < n; ind++){
            for(int k = 0; k <= target; k++){
                bool notTake = dp[ind - 1][k];
                bool take = false;
                if(nums[ind] <= k) take = dp[ind - 1][k - nums[ind]];
                dp[ind][k] = take || notTake;
            }
        }

        int mini = 1e9;
        int s1 = target, s2 = 0; 
        for(int k = target; k >= 0; k--){
            if(dp[n - 1][k]){
                s1 = k;
                s2 = target - k;
            }
            mini = min(mini, abs(s1 - s2));
        }

        return mini;
    }
};


int main(){

    int n; cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    
    Solution sol;

    // Note that this solution assumes the absence of negative numbers in the array nums;
    cout << sol.minimumDifference(nums);

}
