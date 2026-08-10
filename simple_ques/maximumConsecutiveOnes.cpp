#include<vector>

using namespace std;

// Although this solution is very simple from the way it looks but is actually deep in understanding.
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int j = 0;
        int n = nums.size();
        int ans = 0, counter = 0;
        for(int j = 0; j < n; j++){
            if(nums[j] == 1) counter++;
            else counter = 0;
            ans = max(counter, ans);
        }
        return ans;
    }
};
