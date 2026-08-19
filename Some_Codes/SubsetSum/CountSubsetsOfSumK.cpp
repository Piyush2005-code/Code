#include<iostream>
#include<vector>


using namespace std;


int count(vector<int>& nums, int target){
    int n = nums.size();
    vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(target + 1, 0));

    for(int i = 0; i < n; i++) dp[i][0] = 1;
    dp[0][nums[0]] = 1;

    for(int i = 1; i < n; i++){
        for(int tar = 1; tar <= target; tar++){
            int notTake = dp[i - 1][tar];
            int take = 0;
            if(nums[i] <= tar) take = dp[i - 1][tar - nums[i]];
            dp[i][tar] = take + notTake;
        }
    }
    
    return dp[n - 1][target];
}

int main(){


}
