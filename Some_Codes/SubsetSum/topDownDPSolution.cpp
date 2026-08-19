#include<iostream>
#include<vector>


using namespace std;


class SubsetSum{
    
    private:
    int n, target;
    vector<int> nums;
    vector<vector<bool>> dp;

    public:
    SubsetSum(vector<int> arr, int t) : nums(arr), target(t) {
        this->n = nums.size();
        this->dp = vector<vector<bool>>(n, vector<bool>(target + 1, false));
        for(int i = 0; i < nums.size(); i++){
            dp[i][0] = true;
        }
        if(nums[0] <= target) dp[0][nums[0]] = true;
    }

    int solve(){
        for(int ind = 1; ind < this->n; ind++){
            for(int k = 0; k <= target; k++){
                bool notTake = dp[ind - 1][k];
                bool take = false;
                if(nums[ind] <= k) take = dp[ind - 1][k - nums[ind]];
                dp[ind][k] = take || notTake;
            }
        }
        return dp[this->n - 1][target];
    }
};


// Recursive Solution in O(2^N) time

bool solve(vector<int>& nums, int i, int target){
    if(target == 0) return true;
    if(i == 0) return nums[i] == target;
    bool notTake = solve(nums, i - 1, target);
    bool take = false;
    if(nums[i] <= target) take = solve(nums, i - 1, target - nums[i]);
    return take || notTake;
}



int main(){


    int n; 
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int target; cin >> target;

    SubsetSum ssum(nums, target);
    cout << ssum.solve();
    cout << solve(nums, n - 1, target);

}
