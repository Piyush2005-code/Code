#include<iostream> // For standard Input and Output streams
#include<algorithm> // For the Algorithm Functions
#include<vector> // For the Vectors of data types.

using namespace std;

int main(){

    vector<int> nums = {10, 20, 15, 30, 5, 55, 80};

    sort(nums.begin(), nums.end());
    vector<int>::iterator it = nums.begin();
    advance(it, 2); // advances the iterator by the bidirectional distance argument.
    advance(it, 3); // If you enter a negative value, it will go backwards
    cout<< nums[distance(nums.begin(), it)]; // Prints the element at the index = 5 for the sorted vector nums.



}