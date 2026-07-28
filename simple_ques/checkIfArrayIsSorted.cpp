#include<vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int dec = 0;
        for(int i = 1; i <= nums.size(); i++) {
            if(nums[i - 1] > nums[i % nums.size()]) dec++;
        }
        return dec <= 1;
    }
};

// Here the solution essentially maintains the fact that the array only decrements in it's
// current consecutive elements, but also should maintain that the array is circular, so the last case should also be checked.
