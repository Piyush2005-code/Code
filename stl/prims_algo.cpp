#include<iostream>
#include<queue>

using namespace std;

struct edge{
    int v;
    int parent;
    int w;
};

//Compare edge struct elements by their weights.
struct comp_for_edge{
    bool operator()(const edge& a, const edge& b) const {
        return a.w > b.w;
    }
};

void print_adjlist(vector<vector<pair<int, int>>> adj){
    int N = adj.size() - 1;
    for(int i = 1; i < N + 1; i++){
        cout<< "Parent: "<< i<< " --> {";
        int n = adj[i].size();
        for(int j = 0; j < n; j++){
            int v = adj[i][j].first;
            int w = adj[i][j].second;
            if(j < n - 1) cout<< "{"<< v<< ", "<< w<< "}, ";
            else cout<< "{"<< v<< ", "<< w<< "}";
        }
        cout<< "}\n";
    }
}

class Graph{
    private:
    vector<vector<pair<int, int>>> adj;
    int N;

    public:
    Graph(int N){
        adj = vector<vector<pair<int, int>>>(N + 1);
        this->N = N;
    }

    vector<vector<pair<int, int>>> get_adj(){
        return adj;
    }
    
    int get_number_of_vertices(){
        return N;
    }

    void add_edge(int u, int v, int w){
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

};

class prims{
    private:
    vector<int> parent;
    vector<bool> inMST;
    priority_queue<edge, vector<edge>, comp_for_edge> pq;
    vector<vector<pair<int, int>>> adj;

    public:
    prims(Graph g){
        int N = g.get_number_of_vertices();
        parent = vector<int>(N + 1);
        inMST = vector<bool>(N + 1, false);
        inMST[0] = true;
        adj = g.get_adj();
    }

    int solve(int start, vector<int>& parent){
        pq.push({start, -1, 0});
        int min_weight = 0;

        while(!pq.empty()){
            int curr = pq.top().v;
            int curr_parent = pq.top().parent;
            int curr_weight = pq.top().w;
            pq.pop();

            if(inMST[curr]) continue;
            else{
                min_weight += curr_weight;
                inMST[curr] = true;
                parent[curr] = curr_parent;
                for(auto vw: adj[curr]){
                    int v = vw.first;
                    int w = vw.second;
                    pq.push({v, curr, w});
                }
            }
        }
        return min_weight;
    }

    vector<vector<pair<int, int>>> get_adjlist(vector<int> parent){
        int N = parent.size() - 1;
        vector<vector<pair<int, int>>> adj(N + 1);
    
        for(int i = 1; i < N + 1; i++){
            if(parent[i] != -1){
                adj[parent[i]].push_back({i, -1});
            }
        }
        return adj;
    }

};


int main(){

    int n, m; cin>> n>> m;
    Graph g(n);
    int u, v, w;

    for(int i = 0; i < m; i++){
        cin>> u>> v>> w;
        g.add_edge(u, v, w);
    }
    cout<< "\n\nThe Adjacency list of the original graph:\n";
    print_adjlist(g.get_adj());

    prims solver(g);
    
    vector<int> parent(n + 1);
    int weight = solver.solve(1, parent);

    vector<vector<pair<int, int>>> MST_adj = solver.get_adjlist(parent);

    cout<< "\n\nThe Adjacency list of the prims MST graph:\n";
    print_adjlist(MST_adj);
    cout<< "\n\nThe weight of the prims MST graph: "<< weight;
}
