#include<iostream>
#include<vector>


using namespace std;

// For now I will only apply the upper_bound and lower bound on arrays

// The function returns the first instance of the index of the array such that the element on that index is greater than or equal to the given target.
int upper_bound(vector<int>& nums, int target){
    int n = nums.size();
    int i = 0, j = n - 1;
    int ans = -1;
    int mid;

    while(i <= j){
        mid = j - (j - i) / 2;
        if(nums[mid] >= target){
            ans = mid;
            j = mid - 1;
        } else {
            i = mid + 1;
        }
    }
    return ans;
}



int main(){
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << upper_bound(nums, 5);

}
