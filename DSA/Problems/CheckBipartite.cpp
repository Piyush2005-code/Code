#include<iostream>
#include<vector>
#include<queue>

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

    bool checkBipartite(){
        vector<int> color(N + 1, -1);
        color[1] = 0;
        queue<int> q; q.push(1);

        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v: adj[u]){
                if(color[v] == -1){
                    q.push(v);
                    color[v] = 1 - color[u];
                }
                if(color[v] == color[u]){
                    return false;
                }
            }
        }
        return true;
    }

};


int main(){
    int m;
    Graph g();





}