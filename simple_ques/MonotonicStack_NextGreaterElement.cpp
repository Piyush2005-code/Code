#include<iostream>
#include<stack>
#include<vector>


using namespace std;


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        unordered_map<int, int> mp;

        vector<int> ans1(n1), ans2(n2);
        stack<int> st;

        for(int i = 0; i < n2; i++){
            mp[nums2[i]] = i;
        }

        for(int i = n2 - 1; i >= 0; i--){
            while(!st.empty() && nums2[i] >= nums2[st.top()]) st.pop();
            ans2[i] = st.empty() ? -1 : nums2[st.top()]; // we have to store the actual elements of the nums2[i] array, in the ans2[] array, that will make the ans2[] be the array from which we can map out things...
            st.push(i);
        }

        for(int i = 0; i < n1; i++){
            ans1[i] = ans2[mp[nums1[i]]];
        }

        return ans1;
    }
};


void printVector(vector<int> vect){
    cout << endl;
    for(int i = 0; i < vect.size(); i++){
        cout << vect[i] << " ";
    }
    cout << endl;
}


int main(){
    int n1, n2;
    cout << "Enter the number of elements of both the arrays : \n";
    cin >> n1;
    cin >> n2;
    vector<int> nums1(n1), nums2(n2);


    cout << "\nEnter the elements of the first array : \n";
    for(int i = 0; i < n1; i++){
        cin >> nums1[i];
    }

    cout << "\nEnter the elements of the second array : \n";
    for(int i = 0; i < n2; i++){
        cin >> nums2[i];
    }
    
    Solution sol;

    printVector(sol.nextGreaterElement(nums1, nums2));

}
