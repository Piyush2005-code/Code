#include <algorithm>
#include<iostream>
#include<vector>
#include<queue>


using namespace std;


class Solution{
    public:

        bool check_grid(vector<vector<int>>& grid){
            for(int i = 0; i < grid.size(); i++){
                for(int j = 0; j < grid[0].size(); j++){
                    if(grid[i][j] == 1) return false;
                }
            }
            return true;
        }

        bool isSafe(int& x, int& y, int& m, int& n){
            return (x < m && y < n && x >= 0 && y >= 0);
        }

        int orangesRotting(vector<vector<int>>& grid){
            int m = grid.size();
            if(m == 0) return -1;
            int n = grid[0].size();
            
            queue<vector<int>> q;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] == 2){
                        q.push({i, j, 0});
                    }
                }
            }
            int current_time = -1;
            vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
            int max_time = -1;
            int x, y;
            vector<int> curr;
            while(!q.empty()){
                curr = q.front();
                q.pop();
                x = curr[0];
                y = curr[1];
                current_time = curr[2] + 1;

                max_time = max(current_time, max_time);
                
                for(int k = 0; k < 4; k++){
                    int nx = x + directions[k][0];
                    int ny = y + directions[k][1];
                    if(isSafe(nx, ny, m, n) && grid[nx][ny] == 1){
                        q.push({nx, ny, current_time});
                        grid[nx][ny] = 2;
                    }
                }
            }
            return current_time - 1;
        }
};


int main(){
    int m, n;

    cout<< "Enter the number of Rows and Columns for the grid: ";
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter the elements for the " << m << " Rows and " << n << " Columns of the grid:" << endl;
    for(int i = 0 ; i < m ; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    for(int i = 0 ; i < m ; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    
    Solution sol;
    cout<< sol.orangesRotting(grid);

}
