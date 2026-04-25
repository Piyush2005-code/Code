#include<iostream>
#include<stack>
#include<vector>
#include<map>

using namespace std;
//Using adjacency list:
class graph{
    private:
    map<int, vector<int>> adj;

    void dfs_recur(vector<int>& res, vector<int>& visited, int i){
        res.push_back(i);
        visited[i] = 1;
        // if(!adj[i].empty())
        for(auto x: adj[i]){
            if(!visited[x])
                dfs_recur(res, visited, x);
        }
        
    }

    public:
    void add_edge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> DFS_recur(int start){
        vector<int> res;
        vector<int> visited(adj.size() + 1, 0);
        dfs_recur(res, visited, start);
        return res;
    }

};



int main(){

    graph G;

    G.add_edge(1, 2);
    G.add_edge(1, 5);
    G.add_edge(1, 3);
    G.add_edge(2, 4);
    G.add_edge(4, 5);
    G.add_edge(1, 9);
    G.add_edge(1, 6);
    G.add_edge(6, 8);
    G.add_edge(6, 7);
    G.add_edge(7, 8);
    G.add_edge(5, 7);
    G.add_edge(3, 5);

    // G.add_edge(1, 2);
    // G.add_edge(1, 3);
    // G.add_edge(2, 4);
    // G.add_edge(3, 4);

    vector<int> visitation_array = G.DFS_recur(9);

    for(int x: visitation_array){
        cout<< x<< " ";
    }
    cout<< "\n";
}