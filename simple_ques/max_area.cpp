#include <iostream>
#include <stack>
#include <vector>


class Solution {
public:
    int maxArea(vector<int>& height){
        int n = height.size();
        int i = 0, j = n - 1;
        int area = 0;

        while(i < j){

            int area = max(area, min(height[i], height[j]) * (j - i));

            if (height[i] < height[j]) {
                i++;
            }
            else {
                j--;
            }
        }   
        return area;
    }
};
