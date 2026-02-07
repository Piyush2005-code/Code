#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

struct ComparePair{
    bool operator()(pair<int, int> const& p1, pair<int, int> const& p2){
        return p1.first < p2.first;
    }
};

class Graph{
    private:
    void add_edge(int u, int v, int w){
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    public:
        vector<vector<pair<int, int>>> adj;

        Graph(int n, int m){
            adj = vector<vector<pair<int, int>>>(n);
            cout<< "Enter the values for the edges and weights: \n";
            for(int i = 0; i < m; i++){
                int u, v, w;
                cin>> u>> v>> w;
                add_edge(u, v, w);
            }
            cout<< "The current AdjList of the graph is: " << endl;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < adj[i].size(); j++)
                    cout<< "Edge: "<< i<< "---"<< adj[i][j].second<< "--->"<< adj[i][j].first<< endl;
            }
        }

};


vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int src, int target){

    priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePair> pq; // Stores the pair of {dist, node} in a priority queue such that the ones having lesser values of dist are placed on a higher priority.
    int n = adj.size();
    vector<int> dist(n, INT_MAX - 8888);
    dist[src] = 0;
    vector<bool> visited(n, false);
    vector<int> prev(n);
    prev[src] = src;


    visited[0] = true;
    pq.push({0, 0});
    
    while(!pq.empty()){
        pair<int, int> x = pq.top();
        pq.pop();

        for(auto pr: adj[x.second]){ // This pair is different from the one in the priority queue, this pair is of {node, weight} and is having the connection node and distance to that node from x.second.
            if(pr.second + x.first < dist[pr.first]){
                prev[pr.first] = x.second;
                dist[pr.first] = pr.second + x.first;
                pq.push({dist[pr.first], pr.first});
            }
        }
    }
    return prev;
}

void printpath(vector<int> const& prev, int idx){
    if(prev[idx] == idx){
        cout<< idx;
        return;
    }
    printpath(prev, prev[idx]);
    cout<< "--->"<< idx;
}


int main(){

    int n, m;
    cout<< "Enter the number of Nodes and edges: ";
    cin>> n>> m;

    Graph g = Graph(n, m);

    int src, target;
    cout<< "Enter the source and the target node values: ";
    cin>> src>> target;

    vector<int> prev = dijkstra(g.adj, src, target);

    printpath(prev, target);

}