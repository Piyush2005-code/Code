#include<iostream>
#include<vector>
#include<queue>


using namespace std;


class Image{
    private:
        int m, n;
        vector<vector<int>> grid;

        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        bool isSafe(int x, int y, int m, int n){
            return (0 <= x && x < m) && (0 <= y && y < n);
        }
        
        //Here I was adding the grid[sr][sc] value for the oldColor, which made it problematic as the oldColor got changed
        //as it was passed as a reference, it changed when the first set of coordinates were pushed...
        //So from that moment on the code never really colored any other neighbours, 
        //when the if() condition occurred in the level by level traversal.
        void bfs(int sr, int sc, const int& oldColor, int& newColor){
            queue<vector<int>> q;
            grid[sr][sc] = newColor;
            q.push({sr, sc});
            vector<int> curr(2);
            
            while(!q.empty()){
                curr = q.front();
                q.pop();
                int x = curr[0];
                int y = curr[1];
                
                for(vector<int> dir: directions){
                    int x_new = x + dir[0];
                    int y_new = y + dir[1];
                    
                    if(isSafe(x_new, y_new, m, n) && grid[x_new][y_new] == oldColor){
                        grid[x_new][y_new] = newColor;
                        q.push({x_new, y_new});
                    }
                }
            }
        }

        void dfs(int sr, int sc, const int& oldColor, int& newColor){
            // if(isSafe(sr, sc, m, n) && grid[sr][sc] == oldColor){
            //     grid[sr][sc] = newColor;
            // }
            // else if(!isSafe(sr, sc, m, n) || grid[sr][sc] == newColor){return;}
            if(!isSafe(sr, sc, m, n) || grid[sr][sc] == newColor) return;
            else if(grid[sr][sc] == oldColor) grid[sr][sc] = newColor;
            else {return;}

            for(vector<int> dir : directions){
                int x = sr + dir[0]; 
                int y = sc + dir[1];

                dfs(x, y, oldColor, newColor);
            }
        }
        
    public:
        Image(int m, int n): m(m), n(n) {
            //It is extremely necessary that the grid variable which is being assigned the vector<vector<int>> is the class attribute only
            //Here "this" is not really necessary but the grid variable must not be defined again, as that would create another local instance of the variable and ruin things.
            this->grid = vector<vector<int>>(m, vector<int>(n, 0));
            take_inputs(m, n);
        }

        void take_inputs(int m, int n){
            cout<< "Enter the image pixel values:\n";
            int x;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    cin>> x;
                    grid[i][j] = x;
                }
            }
        }
        
        void print(){
            cout<< "\nCurrent State of the grid:\n\n";
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    cout<< grid[i][j]<< " ";
                }
                cout<< endl;
            }
        }
        
        void floodFillBFS(int start_row, int start_col, int oldColor, int newColor){
            bfs(start_row, start_col, oldColor, newColor);
            print();
        }
        void floodFillDFS(int start_row, int start_col, int oldColor, int newColor){
            dfs(start_row, start_col, oldColor, newColor);
            print();
        }

};

int main(){

    int m, n;
    cout<< "Enter the dimensions of the image:\n";
    cin >> m >> n;
    Image img(m, n);

    img.floodFillBFS(0, 0, 1, 2);
    img.floodFillDFS(0, 0, 1, 2);

}