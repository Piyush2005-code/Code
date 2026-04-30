#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void print_vector(vector<int> vec);


// The functions in the below implementation assumes that the input graph will be one connected component only.
class graph{
    private:
        vector<vector<int>> adjlist;
        int n;
        int m;

        void dfsRec(int start_point, vector<bool>& visited, vector<int>& parent, vector<int>& res){
            res.push_back(start_point);
            visited[start_point] = true;

            for(int x: adjlist[start_point]){
                if(!visited[x]){
                    dfsRec(x, visited, parent, res);
                    parent[x] = start_point;
                }
            }
        }

        void add_directed_edge(int x, int y){
            adjlist[x].push_back(y);
        }

        void add_undirected_edge(int x, int y){
            adjlist[x].push_back(y);
            adjlist[y].push_back(x);
        }

    public:
        graph(int n, int m): n(n), m(m){
            adjlist = vector<vector<int>>(this->n);
        }
        
        void take_input(){
            cout<< "Input "<< m<< "pairs of numbers showing the directed edge from one node to another: \n";
            for(int i = 0; i < m; i++){
                int x, y;
                cin>> x>> y;
                add_directed_edge(x, y);
            }
        }

        vector<int> dfs(int start){
            vector<int> parent(n, -1);
            vector<bool> visited(n, false);
            vector<int> res;
            dfsRec(start, visited, parent, res);
            return parent;
        }

        vector<int> bfs(int start){
            queue<int> q;
            vector<bool> visited(n, false);
            vector<int> parent(n, -1);
            q.push(start);
            visited[start] = true;
            
            while(!q.empty()){
                int curr = q.front(); 
                q.pop();
                for(int x: adjlist[curr]){
                    if(!visited[x]){
                        q.push(x);
                        parent[x] = curr;
                        visited[x] = true;
                    }
                }
            }
            return parent;
        }
};


void print_vector(vector<int> vec){
    for(int x : vec){
        cout<< x<< " ";
    }
    cout<< endl;
}


int main(){
    
    int n, m;
    cin>> n>> m;
    graph g = graph(n, m);
    g.take_input();
    print_vector(g.dfs(0));
    print_vector(g.bfs(0));

}





