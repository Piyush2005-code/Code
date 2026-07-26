#include<iostream>
#include<vector>


using namespace std;


class Solution {
public:

    // First try: O(N^2)
    // int findDuplicate(vector<int>& nums) {
    //     int x;
    //     for(int i = 0; i < nums.size(); i++){
    //         x = nums[i];
    //         for(int j = i + 1; j < nums.size(); j++){
    //             if(x == nums[j]) return x;
    //         }
    //     }
    //     return -1;
    // }

    // LinkedList cycle detectio(Floyd's cycle detection algorithm)
    int findDuplicate(vector<int>& nums){
        int slow = 0, fast = 0;

        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }

        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};



// The  constraints in the input are such that if the length of the array nums is n + 1, then the range of elements shall be [1, n].
int main(){

    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    Solution sol;

    cout << sol.findDuplicate(nums);

}
