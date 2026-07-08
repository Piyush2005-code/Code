#include<iostream>
#include<vector>


using namespace std;


int main(){

    int n;
    vector<int> nums;
    int x;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x;
        nums.push_back(x);
    }

    // cout << nums;
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }

    cout << "\nNa you cannot just print a vector, I feel there should be such an abstraction implemented or else this is just something that can be done, although if we want to use abstractions than can refer to python, but still this is good.";

}

