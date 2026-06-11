#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height){
        int n = height.size();
        int i = 0, j = n - 1;
        int area = 0;

        while(i < j){
            //I made a mistake that I defined the area variable again inside the loop, that kept making a variable having random value and then assigning the wrong variable.
            area = max(area, min(height[i], height[j]) * (j - i));
            cout<< area << endl;
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


int main(){
    int n;
    cout<< "Enter the number of elements of the heights array: ";
    cin >> n;
    vector<int> height(n);
    cout<< "\nEnter the " << n << " element of the heights array:";
    for(int & x : height){
        cin >> x;
    }
    Solution sol;
    cout<< "The maximum area in the container is " << sol.maxArea(height);
}
