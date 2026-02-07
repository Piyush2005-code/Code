#include<iostream>
#include<queue>
#include<utility>
#include<climits>


using namespace std;


struct ComparePair{
    bool operator()(pair<int, int> const& p1, pair<int, int> const& p2){
        return p1.first < p2.first;
    }
};


vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int src, int target){

    priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePair> pq; // Stores the pair of {dist, node} in a priority queue such that the ones having lesser values of dist are placed on a higher priority.
    int n = adj.size();
    vector<int> dist(n, INT_MAX - 8888);
    dist[src] = 0;
    vector<bool> visited(n, false);

    visited[0] = true;
    pq.push({0, 0});
    
    while(!pq.empty()){
        pair<int, int> x = pq.top();
        pq.pop();

        for(auto pr: adj[x.second]){ // This pair is different from the one in the priority queue, this pair is of {node, weight} and is having the connection node and distance to that node from x.second.
            if(pr.second + x.first < dist[pr.first]){
                dist[pr.first] = pr.second + x.first;
                pq.push({dist[pr.first], pr.first});
            }
        }
    }
    return dist;
}


class Graph{
    private:
    void add_edge(int x, int y, int w){
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    public:
    vector<vector<pair<int, int>>> adj;

    Graph(int n, int m){
        this->adj = vector<vector<pair<int, int>>>(n);
        for(int i = 0; i < m; i++){
            int x, y, w;
            cin>> x>> y>> w;
            add_edge(x, y, w);
        }
        cout<< "The edges so far added are:\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < adj[i].size(); j++){
                cout<< "Edge: "<< i<< "-->"<< adj[i][j].first<< " with the weight of: "<< adj[i][j].second<< endl;
            }
        }
    }


};


int main(){

    int n, m;

    cout<< "Enter the Number of nodes and edges: ";
    cin>> n>> m;

    Graph g = Graph(n, m);

    int src, target;

    cout<< "Enter the source and target nodes for Dijkstra's Algorithm: ";
    cin>> src>> target;

    vector<int> dist = dijkstra(g.adj, src, target);

    for(int i = 0; i < n; i++){
        if(i < n - 1){
            cout<< dist[i]<< " ";
        }
        else{
            cout<< dist[i];
        }
    }

}

