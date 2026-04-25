#include<iostream>
#include<string>
#include<map>
#include<list>
#include<queue>

using namespace std;
//Using Adjacency list:
class undirected_graph{
    private:
    map<int, vector<int>> adj;

    public:
    void add_edge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> BFS(int i){
        if(adj.empty()) return vector<int>(0);
        queue<int> q;
        vector<int> visited(adj.size() + 1, 0);
        q.push(i); visited[i] = 1;
        vector<int> res;
        int curr;

        while(!(q.empty())){
            curr = q.front();
            q.pop();
            res.push_back(curr);
            for(auto x: adj[curr]){
                if(!visited[x]){
                    q.push(x); visited[x] = 1;
                }
            }
        }

        return res;
    }


};



int main(){

    undirected_graph G;

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

    vector<int> visitation_array = G.BFS(2);

    for(int x: visitation_array){
        cout<< x<< " ";
    }
    cout<< "\n";
}