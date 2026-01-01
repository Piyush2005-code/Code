#include<iostream>
#include<stack>
#include<vector>


using namespace std;

class Graph{

    public:
    int N;
    vector<vector<int>> adj;

    Graph(int N){
        this->N = N;
        adj = vector<vector<int>>(N + 1);
    }

    void add_edge(int u, int v){
        adj[u].push_back(v);
    }

    void DFS(const int& start, vector<bool>& inStack, vector<bool>& visited, bool& DAG, vector<vector<int>>& adj){
        inStack[start] = true;
        visited[start] = true;

        for(int x: adj[start]){
            if(!visited[x] && !inStack[x]){
                DFS(x, inStack, visited, DAG, adj);
                if(DAG == true) break;
            }
            else if(inStack[x]){
                DAG = true;
            }
        }

        inStack[start] = false;
    }

    bool checkDAG(){
        vector<bool> visited(N + 1, false);
        vector<bool> inStack(N + 1, false);
        bool DAG = false;

        for(int i = 1; i < N + 1; i++)
            if(!visited[i])
                DFS(i, inStack, visited, DAG, adj);
        
        return DAG;
    }

};

int main(){
    int n, m;
    cin>> n, m;
    Graph g(n);

    int u, v;
    for(int i = 0; i < m; i++){
        cin>> u>> v;
        g.add_edge(u, v);
    }

    if(g.checkDAG()){
        cout<< "The Graph is a DAG";
    }
    else{
        cout<< "The Graph is not a DAG";
    }

}