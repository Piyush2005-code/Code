#include<iostream>
#include<vector>
#include<stack>


using namespace std;


class Solution{
    public:
        int largestRec(vector<int>& heights){
            stack<int> st;
            int n = heights.size();
            vector<int> PSE(n, -1);
            vector<int> NSE(n, n);

            for(int i = 0; i < n; i++){
                while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
                PSE[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }
            
            st = stack<int>();

            for(int i = n -1; i >= 0; i--){
                while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
                NSE[i] = st.empty() ? n : st.top();
                st.push(i);
            }

            int maxArea = 0;
            for(int i = 0; i < n; i++){
                maxArea = max(maxArea, heights[i] * (NSE[i] - PSE[i] - 1));
            }
            return maxArea;
        }
};


int main(){
    cout << "Enter the number of elements for the array : ";
    int n; 
    cin >> n;
    
    vector<int> heights(n);

    cout << "Now enter the elements of the array : \n";
    for(int i = 0; i < n; i++){
        cin >> heights[i];
    }

    Solution sol;
    int maxArea = sol.largestRec(heights);
    cout << "The largest area of the rectangle inside of the histogram is " << maxArea;

}
