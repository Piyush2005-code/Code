#include<iostream>
#include<vector>



using namespace std;


int lowerBound(vector<int>& nums, int target){
    int n = nums.size();
    int i = 0, j = n - 1;

    int ans = -1;
    int mid;

    while(i <= j){
        mid = j + (j - i) / 2;

        if(nums[mid] < target){
            ans = mid;
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }

    return ans;
}



int main(){
    int n;
    cout << "Enter the number of elements to put into the vector : \n";
    cin >> n;

    vector<int> nums(n);

    cout << "\nEnter the elements of the array now :\n"
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int target;
    cout << "\nEnter the target of the lowerBound algorithm : ";
    cin >> target;

    cout << lowerBound(nums, target);
}

