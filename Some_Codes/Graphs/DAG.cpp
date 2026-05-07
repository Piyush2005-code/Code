#include<iostream>
#include<vector>


using namespace std;


class graph{
    private:
        vector<vector<int>> adj;
        int n;
        int m;
        void take_inputs(int n, int m){
            cout<< "Enter "<< m<< " pairs of integer numbers that represent directed edges from one to another:\n";
            for(int i = 0; i < m; i++){
                int x, y;
                cin>> x>> y;
                add_edge(x, y);
            }
        }

        void add_edge(int x, int y){
            adj[x].push_back(y);
        }

        bool isCyclic(int start, vector<bool>& visited, vector<bool>& recStack){
            visited[start] = true;
            recStack[start] = true;

            for(int x: adj[start]){
                if(recStack[x]) return true;
                else if(!visited[x]) isCyclic(x, visited, recStack);
            }

            recStack[start] = false;
            return false;
        }
    
    public:
        graph(int n, int m) : n(n), m(m){
            adj = vector<vector<int>>(n);
            take_inputs(n, m);
        }

        bool checkDAG(){
            vector<bool> visited(n, false);
            vector<bool> recStack(n, false);

            for(int i = 0; i < n; i++){
                if(!visited[i]){
                    if(isCyclic(i, visited, recStack)) return true;
                }
            }
            return false;
        }

        vector<int> topologicalSort(){

            
        }

};


int main(){

    int n, m;
    cout<< "Enter the number of nodes and edges:\n";
    cin>> n>> m;
    graph g(n, m);
    if(g.checkDAG()) cout<< "The given graph is a Directed Acyclic Graph\n";
    else{
        cout<< "The given graph is not a Directed Acyclic Graph\n";
    }

}


