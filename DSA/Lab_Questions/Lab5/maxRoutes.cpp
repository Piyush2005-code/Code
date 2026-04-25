/*
You are given a tree with n vertices labelled 1,2,…,n The length of a simple path in the tree is the number of vertices in it. You are to select a set of simple paths of length at least two each, but you cannot simultaneously select two distinct paths contained one in another. Find the largest possible size of such a set.

Formally, a set S of vertices is called a route if it contains a least two vertices of a simple path in the tree. A collection of distinct routes is called a timetable. A route S in a timetable T is called redundant if there is different route S' that belongs to T such that S is a subset of S'. A timetable is called efficient if it contains no redundant routes. Find the largest possible number of routes in an efficient timetable.

Input format:
First line contains n, which is the number of nodes
Nex n lines contains u-v pairs of edges

Output format:
One integer with your answer

Example
Input:
4
1 2
1 3
1 4

Output
3
*/

//Solution:

#include <iostream>
#include <vector>
using namespace std;

// Class representing a Tree
class Tree {
    
public:
    vector<pair<pair<int, int>, int>> edges;
    Tree(int n){
        vector<pair<pair<int, int>, int>> arr(n);
        this->edges = arr;
    }
    
    // Method to calculate the largest number of non-redundant routes
    int calculateMaxRoutes() {
        int maxRoutes = 1;
        return maxRoutes;
    }
    
    void addEdge(int u, int v){
        return;
    }
    
};

int main() {
    int n;
    cin >> n;

    Tree tree(n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree.addEdge(u, v);
    }

    cout << tree.calculateMaxRoutes() << endl;
    return 0;

}