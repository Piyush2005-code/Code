#include<iostream>
#include<queue>
#include<vector>


using namespace std;


class Board{
    private:
        vector<int> moves;
        vector<bool> visited;
        int n;
        int m;
          
        void map_states(int m){
            int x, y;
            cout<< "Enter the mappings for the corresponding snakes and ladders:\n";
            for(int i = 0; i < m; i++){
                cin >> x >> y;
                moves[x] = y;
            }
        }

    public:
        // n is the number of states on board and m is the number of mapping(Ladders or Snakes)
        Board(int n, int m): n(n), m(m){
            moves = vector<int>(n, -1);
            visited = vector<bool>(n, false);
            map_states(m);
        } 

        int getMinMovesBFS(){
            queue<vector<int>> q;
            q.push({0, 0});
            visited[0] = true;
            int dest;
            int dist;

            while(!q.empty()){
                vector<int> curr = q.front();
                dest = curr[0];
                dist = curr[1];

                q.pop();

                if(dest == n - 1) return dist;

                for(int i = dest + 1; i < dest + 6 && i < n; i++){
                    if(!visited[i]){
                        visited[i] = true;

                        dest = (moves[i] != -1) ? moves[i] : i;
                        q.push({dest, dist + 1});
                    }
                }
            } 
            return -1;
        }

    //    int getMinMovesDFS(){
    //    }

};


int main(){

    int n, m;
    cout<< "Enter the number of positions on board: ";
    cin>> n;
    cout<< "Enter the number of mappings(Snakes and Ladders): ";
    cin>> m;

    Board board = Board(n, m);

    cout<< "The minimum number of moves required from BFS: "<< board.getMinMovesBFS()<< endl;
    // cout<< "The same using DFS: "<< board.getMinMovesDFS()<< endl;

}
