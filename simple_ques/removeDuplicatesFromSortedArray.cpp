#include<vector>

using namespace std;


class Solution {
public:
    // This requires two loops, and the second loop shifts in O(n^2)
    // int removeDuplicates(vector<int>& nums) {
    //     int n = nums.size();
    //     for(int i = 0; i < n-1; i++)
    //         if(nums[i] == nums[i + 1]) nums[i] = -9999;

    //     int j = nums.size() - 1, i = nums.size() - 1;
    //     while(j >= 0){
    //         if(nums[j] == -9999){
    //             for(int k = j; k < i; k++){
    //                 nums[k] = nums[k + 1];
    //             }
    //             i--;
    //         }
    //         j--;
    //     }
    //     return i + 1;
    // }

    // This loop should work in O(n);
    int removeDuplicates(vector<int>& nums) {
        int k = 1, n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i - 1]){
                nums[k] = nums[i]; k++;
            }
        }
        return k;
    }
};
