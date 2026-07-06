#include<iostream>
#include<vector>
#include<climits>


using namespace std;

// The Bellman Ford Algorithm can handle negative edge weights and detects negative weighted cycle
class Graph{
    private:
        int n, m;
        vector<vector<int>> edges;
        vector<vector<pair<int, int>>> adjlist;


    public:
        Graph(int n, int m): n(n), m(m){
            adjlist = vector<vector<pair<int, int>>>(n);
            cout << "\nEnter the edge list of the graph : \n";
            int u, v, w;
            for(int i = 0; i < m; i++){
                cin >> u >> v >> w;
                adjlist[u].push_back({v, w});
                // adjlist[v].push_back({u, w});
                edges.push_back({u, v, w});
            }
        }


        void printAdjlist(){
            cout << endl;
            for(int i = 0; i < this->n; i++){
                cout << "\n{" << i << "} -->";
                for(auto [v, w] : this->adjlist[i]){
                    cout << "{" << v << ", " << w << "} ";
                }
            }
        }


        void printEdgelist(){
            cout << endl;
            for(int i = 0; i < m; i++){
                cout << edges[i][0] << ", " << edges[i][1] << ", " << edges[i][2] << endl;
            }
        }


        vector<int> bellmanFord(int src){
            vector<int> dist(this->n, INT_MAX);
            dist[src] = 0;
            int u, v, w;

            for(int i = 0; i < this->n; i++){
                for(auto edge : this->edges){
                    u = edge[0];
                    v = edge[1];
                    w = edge[2];

                    if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                        if(i == this->n - 1) return {-1};
                        dist[v] = dist[u] + w;
                    }
                }
            }
            return dist;
        };
};


void print_vector(vector<int> nums){
    cout << "\n";
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
}


int main(){

    int n, m;
    cout << "\nEnter the number of V and E : \n";
    cin >> n >> m;

    Graph g = Graph(n, m);

    g.printAdjlist();
    g.printEdgelist();
    

    int src;
    cout << "\nEnter the node to start the bellman ford algorithm from : \n"; cin >> src;
    print_vector(g.bellmanFord(src));
    //Note that here I am just using a value returned by the method, so if I do call by reference in print_vector, then it wouldn't work because it requires to have a variable/container storing some value.

}
