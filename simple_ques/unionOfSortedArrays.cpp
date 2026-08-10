#include<vector>

using namespace std;

class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();

        while(i < n1 && j < n2){
            // This particular if-else loop only checks if the duplicated elements are also present in the array or not.
            if(nums1[i] < nums2[j]){
                if(ans.empty() || ans.back() != nums1[i]){
                    ans.push_back(nums1[i]); i++;
                } else i++;
            } else if(nums2[j] < nums1[i]) {
                if(ans.empty() || ans.back() != nums2[j]){
                    ans.push_back(nums2[j]); j++;
                } else j++;
            } else {
                if(ans.empty() || ans.back() != nums1[i]){
                    ans.push_back(nums1[i]); i++; j++;
                } else {
                    i++; j++;
                }
            }
        }

        while(i < n1){
            if(ans.empty() || ans.back() != nums1[i]){
                ans.push_back(nums1[i]); i++;
            } else i++;
        }

        while(j < n2){
            if(ans.empty() || ans.back() != nums2[j]){
                ans.push_back(nums2[j]); j++;
            } else j++;
        }

        return ans;
};
