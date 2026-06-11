#include <iostream>
#include <queue>


using namespace std;


class Solution{
    public:
        int orangeRotting(vector<vector<int>>& grid){
            

        }

};


int main(){
    
    int m, n;
    cin>> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[m][n];

    Solution sol;
    cout<< sol.orangeRotting(grid);
}
