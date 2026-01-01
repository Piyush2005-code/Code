#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
    // Step 1: Build the graph
    unordered_map<int, vector<int>> graph;
    for (auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    
    // Step 2: BFS traversal (node, probability, time_elapsed)
    queue<tuple<int, double, int>> q;
    unordered_set<int> visited;
    q.push({1, 1.0, 0});
    visited.insert(1);
    
    while (!q.empty()) {
        auto [node, prob, time] = q.front();
        q.pop();
        
        if (time == t) {
            return (node == target) ? prob : 0.0;
        }
        
        // Count unvisited neighbors
        int unvisitedCount = 0;
        for (int neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                ++unvisitedCount;
            }
        }
        
        // If no unvisited neighbors, frog stays
        if (unvisitedCount == 0) {
            if (node == target) return prob;
            continue;
        }
        
        // Propagate probability to each unvisited neighbor
        for (int neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push({neighbor, prob / unvisitedCount, time + 1});
                visited.erase(neighbor);  // Backtrack
            }
        }
    }
    
    return 0.0;
}

int main(){

    int n;
    vector<vector<int>> edges;
    int t;
    int target;
    double result = frogPosition(n, edges, t, target);

    cout<< result;
}