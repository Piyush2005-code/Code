#include<iostream>
#include<stack>
#include<queue>
#include<vector>


using namespace std;


class Graph{
    private:
        int n, m;
        vector<vector<int>> adj;
        
        void take_inputs(int m){
            int x, y;
            for(int i = 0; i < m; i++){
                cin >> x >> y;
                add_edge(x, y);
            }
        }

        void add_edge(int x, int y){
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

    public:
        Graph(int n, int m): n(n), m(m){
            adj = vector<vector<int>>(n);
            take_inputs(m);
        }

        bool checkBipartite(){
            int start = 0;
            
        }
};