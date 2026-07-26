#include<iostream>
#include<vector>
#include<queue>


using namespace std;


class Graph{
    private:
        vector<vector<vector<int>>> adjlist;
        int V, E;

    public:
        Graph(int _V, int _E) : V(_V), E(_E){
            adjlist = vector<vector<vector<int>>>(_V, vector<vector<int>>());
            cout << "\nEnter the edge list of the graph : \n";
            int u, v, wt;
            for(int i = 0; i < _E; i++){
                cin >> u >> v >> wt;
                adjlist[u].push_back({v, wt});
                adjlist[v].push_back({u, wt});
            }
        }


        vector<int> primsAlgo(int start){
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, start});

            vector<int> parent(V);
            vector<bool> visited(V, false);
            parent[start] = -1;
            
            // Well this is a part of the mistake;
            // visited[start] = true;
            
            while(!pq.empty()){
                pair<int, int> top = pq.top();
                pq.pop();

                int u = top.second;

                if(visited[u]){
                    continue;
                }
                else visited[u] = true;
                // int wt = top.first;

                for(auto &v : adjlist[u]){
                   if(!visited[v[0]]){
                        pq.push({v[1], v[0]});
                        parent[v[0]] = u;
                   }
                }

            }
            
            return parent;
        }
};


void printVector(vector<int>& vect){
    cout << "\n";
    for(int i = 0; i < vect.size(); i++){
        cout << vect[i] << " ";
    }
    cout << "\n";
}


int main(){
    int V, E;
    cout << "Enter the number of Vertices and Edges for the graph : \n";
    cin >> V >> E;

    Graph g(V, E);

    int start;
    cout << "\nEnter the node to start from : \n";\
    cin >> start;

    vector<int> parent = g.primsAlgo(start);

    printVector(parent);

}
