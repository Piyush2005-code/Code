#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Graph{
private:
    vector<vector<int>> adj;
    int N;

public:
    Graph(int N){
        this->N = N;
        adj = vector<vector<int>>(N + 1);
    }

    void add_edge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int start, vector<int>& res){
        vector<int> vis(N + 1, 0);


    }


};
