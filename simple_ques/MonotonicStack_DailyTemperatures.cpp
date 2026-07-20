#include<iostream>
#include <sys/wait.h>
#include<vector>
#include<stack>


using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++) ans[i] = i;

        stack<int> st;

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]) st.pop();
            ans[i] = (st.empty()) ? 0 : (st.top() - ans[i]);
            st.push(i);
        }

        return ans;
    }
};


void printVector(vector<int>& vect){
    cout << "\n";
    for(int i = 0; i < vect.size(); i++){
        cout << vect[i] << " ";
    }
    cout << "\n";
}


int main(){

    int n;
    cout << "Enter the number of elements for the temperatures array : ";
    cin >> n;

    vector<int> temperatures(n);

    cout << "Enter the elements of the temperatures array :\n";

    for(int i = 0; i < n; i++){
        cin >> temperatures[i];
    }

    Solution sol;

    vector<int> waitingDays = sol.dailyTemperatures(temperatures);
    
    printVector(waitingDays);

}
