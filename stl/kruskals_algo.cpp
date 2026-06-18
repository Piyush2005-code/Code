#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

class mergeSort{
    void merge(vector<vector<int>>& edges, int l, int m, int r){
        const int n1 = m - l + 1;
        const int n2 = r - m;

        int k = l;
        
        vector<vector<int>> L(n1);
        // vector<vector<int>> R(n2);

        for(int i = 0; i < n1; i++){
            L[i] = edges[l + i];
        }
        for(int i = 0; i < n2; i++){
            R[i] = edges[m + 1 + i];
        }

        int i = 0; int j = 0;

        while(i < n1 && j < n2){
            if(L[i][2] < R[j][2]){
                edges[k] = L[i]; i++; k++;
            }
            else{
                edges[k] = R[j]; j++; k++;
            }
        }
        while(i < n1){
            edges[k] = L[i]; i++; k++;
        }
        while(j < n2){
            edges[k] = R[j]; j++; k++;
        }

    }

    void mSort(vector<vector<int>>& edges, int l, int r){
        if(l < r){
            int m = l + (r - l) / 2;
            mSort(edges, 0, m);
            mSort(edges, m + 1, r);
            merge(edges, 0, m, r);
        }
    }

    public:
    void print(vector<vector<int>> edges){
        for(vector<int> edge: edges){
            cout<< "| "<< edge[0]<< " | "<< edge[1]<< " | "<< edge[2]<< " |\n";
        }
    }

    void solve(vector<vector<int>>& edges){
        int n = edges.size();
        mSort(edges, 0, n - 1);
    }

};


class DSU{
    public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }
    
    int find(int i){
        return (parent[i] == i) ? i : parent[i] = find(parent[i]);
    }

    void unite(int x, int y){
        int s1 = find(x); int s2 = find(y);
        if(s1 != s2){
            if(rank[s1] < rank[s2]) parent[s1] = s2;
            else if(rank[s1] > rank[s2]) parent[s2] = s1;
            else{
                rank[s1]++; parent[s2] = s1;
            }
        }
    }

};

//Edge List graph
class Graph{
    public:
    vector<vector<int>> edges;

    Graph(int n){
        edges = vector<vector<int>>(n, vector<int>(3));
    }
    // each vector of the outer vector is having the values of (u, v, w).
    

    int kruskals_cost(int n, vector<int>& parent){
        int count = 0, cost = 0;

        mergeSort m_sort;
        m_sort.solve(edges);
        
        DSU dsu(n);

        for(auto edge: edges){
            int u = edge[0], v = edge[1], w = edge[2];
            if(dsu.find(u) != dsu.find(v)){
                dsu.unite(u, v);
                cost += w;
                if(++count == n - 1) break;
            }
        }
        parent = dsu.parent;
        return cost;
    }


};


int main(){

    int n, m;
    cin>> n>> m;

    Graph g(m);

    for(vector<int>& edge: g.edges){
        cin>> edge[0]>> edge[1]>> edge[2];
    }
    vector<int> parent;
    cout<< g.kruskals_cost(n, parent)<< "\n";
    for(int x : parent){
        cout<< x<< " ";
    }

//Trial Solutions.

    // mergeSort m_sort;

    // m_sort.solve(edges);
    // m_sort.print(edges);

}