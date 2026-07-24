#include<iostream>
#include<vector>


using namespace std;

// class Solution{
//     public:
//         // Brute Force Solution:
//         double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
//             int n1 = nums1.size(), n2 = nums2.size();
//             vector<int> res(n1 + n2);
//             int k = 0;
//             int i = 0, j = 0;
//
//             while(i < n1 && j < n2){
//                 if(nums1[i] < nums2[j]){
//                     res[k] = nums1[i];
//                     i++; k++;
//                 } else {
//                     res[k] = nums2[j];
//                     j++; k++;
//                 }
//             }
//
//             while(i < n1){
//                 res[k] = nums1[i];
//                 k++; i++;
//             }
//
//             while(j < n2){
//                 res[k] = nums2[j];
//                 k++; j++;
//             }
//
//             if((n1 + n2) % 2 == 0){
//                 return (res[(n1 + n2) / 2] + res[(n1 + n2) / 2 + 1]) / 2 ;
//             }
//             else return res[(n1 + n2) / 2];
//         }
// };
//

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        // Just making sure that the second array is larger than the smaller
        if (n1 > n2) {
            return findMedianSortedArrays(nums2, nums1);
        }


        int l1, r1, l2, r2, mid1, mid2;
        int i = 0;
        int j = n1;
        while (i <= j) {
            mid1 = (i + j) / 2;
            mid2 = (n1 + n2 + 1) / 2 - mid1; // The +1 is essentially for the 

            l1 = (mid1 == 0 ? INT_MIN : nums1[mid1 - 1]);
            r1 = (mid1 == n1 ? INT_MAX : nums1[mid1]);

            l2 = (mid2 == 0 ? INT_MIN : nums2[mid2 - 1]);
            r2 = (mid2 == n2 ? INT_MAX : nums2[mid2]);

            if (l1 <= r2 && l2 <= r1) {
                if ((n1 + n2) % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else
                    return max(l1, l2);
            }
            if (l1 > r2) j = mid1 - 1;
            else i = mid1 + 1;
        }
        return 0;
    }
};


int main(){


}
