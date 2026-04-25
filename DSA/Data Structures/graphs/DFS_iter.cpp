#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<map>

using namespace std;


class graph{
    private:
    unordered_map<int, vector<int>> adj;

    public:
    void add_edge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> DFS(int start){
        


    }

};