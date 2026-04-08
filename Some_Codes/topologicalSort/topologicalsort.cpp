#include<iostream>
#include<vector>
#include<stack>


using namespace std;


void DFS(int src, vector<vector<int>> &adjlist, vector<bool>& visited, stack<int>& callst);

void DFS(int src, vector<vector<int>> &adjlist, vector<bool>& visited, stack<int>& callst){

    callst.push(src);
    visited[src] = true;
    cout<< src<< ' ';
    for(auto x: adjlist[src]){
        if(!visited[x]) DFS(x, adjlist, visited, callst);
    } 

}

void addEdge(vector<vector<int>> adjlist, int u, int v);

void addEdge(vector<vector<int>> adjlist, int u, int v){
    

}


int main(){
    
    vector<vector<int>> adjlist;
    
    int n, m;

    for(int i = 0; i < m; i++){
        int x, y, w;
        bool repetitionNeeded = false;
        do{
            cin >> x >> y;
            if(x >= n || y >= n){
                repetitionNeeded = true; cout<< "You need to keep the values of nodes less than "<< n<< endl;
                cout<< "Enter the values again: ";
            }
            else{
                repetitionNeeded = false;
                adjlist[x].push_back(y);
            }
        }while(repetitionNeeded);
    }
    
    vector<bool> visited(n, false);
    stack<int> callst;
    DFS(0, adjlist, visited, callst);

}
