#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Map{
    private:
        int m, n;
        vector<vector<char>> grid;

        void take_inputs(int m, int n){
            char c;
            cout<< "Enter the values of the grid:\n";
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    cin>> c;
                    this->grid[i][j] = c;
                }
            }
        }

        bool isSafe(int x, int y, int m, int n){
            return (x >= 0 && x < m) && (y >= 0 && y < n);
        }

        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        void dfs(int i, int j, vector<vector<bool>>& visited){
            visited[i][j] = true;
            for(vector<int> dir : directions){
                int x = i + dir[0];
                int y = j + dir[1];

                if(isSafe(x, y, m, n) && !visited[x][y] && grid[x][y] == 'L'){
                    dfs(x, y, visited);
                }
            }
        }

        void bfs(int i, int j, vector<vector<bool>>& visited){
            queue<vector<int>> q;
            q.push({i, j});
            visited[i][j] = true;
            vector<int> curr(2, 0);

            while(!q.empty()){
                curr = q.front();
                q.pop();
                int x = curr[0];
                int y = curr[1];

                for(vector<int> dir: directions){
                    int x_new = x + dir[0];
                    int y_new = y + dir[1];

                    if(isSafe(x_new, y_new, m, n) && !visited[x_new][y_new] && grid[x_new][y_new] == 'L'){
                        q.push({x_new, y_new});
                        visited[x_new][y_new] = true;
                    }
                }
            }
        }


    public:
        Map(int m, int n) : m(m), n(n){
            grid = vector<vector<char>>(m, vector<char>(n, 'N'));
            take_inputs(m, n);
        }
        int countOfIslandsDFS(){
            vector<vector<bool>> visited(m, vector<bool>(n, false));

            int countOfIslands = 0;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(!visited[i][j] && grid[i][j] == 'L'){
                        dfs(i, j, visited); countOfIslands++;
                    }
                }
            }

            return countOfIslands;
        }

        int countOfIslandsBFS(){
            vector<vector<bool>> visited(m, vector<bool>(n, false));

            int countOfIslands = 0;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(!visited[i][j] && grid[i][j] == 'L'){
                        bfs(i, j, visited); countOfIslands++;
                    }
                }
            }

            return countOfIslands;
        }

};


int main(){

    int m, n;
    cout<< "Enter the number of rows and columns for the grid:\n";
    cin>> m>> n;
    Map mp(m, n);

    cout<< "BFS: "<< mp.countOfIslandsBFS()<< endl;
    cout<< "DFS: "<< mp.countOfIslandsDFS()<< endl;

}