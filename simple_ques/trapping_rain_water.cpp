#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax = 0;
        int rightMax = 0;

        int start = 0; int end = height.size() - 1;

        int totalArea = 0;
        while(start < end){
            leftMax = (leftMax < height[start]) ? height[start] : leftMax;
            rightMax = (rightMax < height[end]) ? height[end] : rightMax;

            if(leftMax < rightMax){
                totalArea += leftMax - height[start];
                start++;
            }
            else{
                totalArea += rightMax - height[end];
                end--;
            }
        }
        return totalArea;
    }
};

int main(){
    int n; cin >> n;

    vector<int> height(n);

    for(int& h: height){
        cin >> h;
    }

    Solution sol;
    cout<< sol.trap(height);
    return 0;
}