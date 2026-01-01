/*
In the futuristic city of Aethelgard, skyscrapers pierce the clouds, casting long shadows over the neon-lit streets. The city is a marvel of engineering, but it faces a unique challenge: the annual monsoon. The rains are so intense that the city planners have decided to turn this problem into a solution by creating a massive rainwater harvesting system using the very skyline of the city.
You are a brilliant sophomore DSA expert and the city's last hope. The city's architects have provided you with a digital elevation map of a city district, represented as an array of non-negative integers height, where each integer is the height of a skyscraper and each has a width of 1 unit.
Your mission is to write a program that calculates the total amount of water that can be trapped between the skyscrapers after a heavy downpour.
Input
A single line containing a list of integers, height, representing the elevation map.
Output
A single integer representing the total units of water that can be trapped.
Sample test cases
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Input: height = [4,2,0,3,2,5]
Output: 9
*/
//Solution:
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        return 0;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    Solution sol;
    cout << sol.trap(height) << endl;

    return 0;
}