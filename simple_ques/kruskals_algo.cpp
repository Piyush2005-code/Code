// This is a simple implementation of the kruskal's algorithm, basically I am implementing it
// in order to once understand it completely
// This implementation only gives the cost of the entire MST such that the tree has traversed V - 1 edges.
#include<iostream>
#include <stdexcept>
#include<vector>
#include<algorithm>


using namespace std;


class DSU{
    private:
        vector<int> parent;
        vector<int> rank;

    public:
        DSU(int _cap){
            parent = vector<int>(_cap);
            rank = vector<int>(_cap, 0);
            for(int i = 0; i < _cap; i++) parent[i] = i;
        }

        int find(int x){
            return (parent[x] == x) ? x : (parent[x] = find(parent[x]));
        }

        void unite(int a, int b){
            int s1 = find(a), s2 = find(b);

            if(s1 == s2){
                return;
            } else if(rank[s1] < rank[s2]){
                parent[s1] = s2;
                // rank[s2]++;
                // Well it turns out you don't increase the size of the tree when one rank is already above another
            } else if(rank[s1] > rank[s2]){
                parent[s2] = s1;
                // rank[s1]++;
            } else {
                parent[s1] = s2; 
                rank[s2]++;
            }
        }
};


bool compare(vector<int> a, vector<int> b){
    return a[2] < b[2];
}


// The implementation requires the user to initialize the class of Graph object with the number of nodes
class Graph{
    private:
        vector<vector<int>> edges;
        int V;

    public:
        Graph(int _V) : V(_V) {}

        void add_edge(int u, int v, int w){
            edges.push_back({u, v, w});
        }

        int kruskalsAlgo(){
            vector<vector<int>> edgelist = edges;
            int count = 0, cost = 0;
            DSU dsu(this->V);
            
            sort(edgelist.begin(), edgelist.end(), compare);

            for(vector<int>& edge : edgelist){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(dsu.find(u) == dsu.find(v)){
                    continue;
                } else {
                    dsu.unite(u, v);
                    cost += w;
                    count++;
                }
            }
            if(count != V - 1) throw runtime_error("The graph is disconnected.");
            return cost;
        }
};


// Main program to run
int main(){
    
    int n, m;
    cout << "Enter the number of nodes and edges of the graph : \n";
    cin >> n >> m;
    
    Graph g(n);

    int u, v, w;
    cout << "Enter the edges of the graph in the format : u, v, w :\n";
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        g.add_edge(u, v, w);
    }

    cout << "\n\nThe cost of the minimum spanning tree of the graph is " << g.kruskalsAlgo();

}
