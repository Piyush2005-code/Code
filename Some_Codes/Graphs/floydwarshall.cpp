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


        vector<vector<int>> floydwarshall(){
            vector<vector<int>> dist(this->n, vector<int>(this->n, INT_MAX));
            for(int i = 0; i < this->n; i++){
                dist[i][i] = 0;
            }

            for(int i = 0; i < this->m; i++){
                dist[edges[i][0]][edges[i][1]] = edges[i][2];
            }

            for(int k = 0; k < this->n; k++){
                for(int i = 0; i < this->n; i++){
                    for(int j = 0; j < this->n; j++){
                        if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                        }
                    }
                }
            }
            return dist;
        }

};


void print_matrix(vector<vector<int>> m){
    for(int i = 0; i < m.size(); i++){
        cout << endl;
        for(int j = 0; j < m[0].size(); j++){
            cout << m[i][j] << " ";
        }
    }
}


int main(){

    int n, m;
    cout << "\nEnter the number of V and E : \n";
    cin >> n >> m;

    Graph g = Graph(n, m);

    g.printAdjlist();
    g.printEdgelist();
    

    print_matrix(g.floydwarshall());
    //Note that here I am just using a value returned by the method, so if I do call by reference in print_vector, then it wouldn't work because it requires to have a variable/container storing some value.

}

