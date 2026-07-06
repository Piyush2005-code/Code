#include<iostream>
#include<vector>


using namespace std;


bool dfs(vector<vector<int>>& adjlist, int x, vector<bool>& visited, vector<bool>& pathVisited){
    if(pathVisited[x]) return true;
    if(visited[x]) return false;
    bool ans = false;
    visited[x] = true;
    pathVisited[x] = true;
    for(auto y : adjlist[x]){
        ans = ans || dfs(adjlist, y, visited, pathVisited);
    }
    pathVisited[x] = false;
    return ans;
}


bool hasCycle(vector<vector<int>> adjlist){
    int n = adjlist.size();
    vector<bool> visited(n, false);
    vector<bool> pathVisited(n, false);
    for(int i = 0; i < n; i++){
        if(dfs(adjlist, i, visited, pathVisited)) return true;
    }
    return false;
}


int main(){

    int m;
    int n;
    cout << "Enter the number of elements and edges in the graph : "; cin >> n >> m;
    int u, v;
    vector<vector<int>> edges;

    for(int i = 0; i < m; i++){
        cin >> u >> v;
        edges.push_back({u, v});
    }

    vector<vector<int>> adjlist(n);
    //conversion of the edge list to adjacency list...
    for(int i = 0; i < m; i++){
        adjlist[edges[i][0]].push_back(edges[i][1]);
        // The algorithm does not work on undirected edges...as in two nodes it returns true when we reach out for the already pathVisited[y] == true vertices, but in reality they also show up when you treat the previously explored node as a neighbor node.
        // adjlist[edges[i][1]].push_back(edges[i][0]);
    }

    cout << ((hasCycle(adjlist)) ? "\nThe graph is cyclic" : "\nThe graph does not contain any cycle");

}

