#include<iostream>


using namespace std;


class DSU{
    private:
        int n;
        vector<int> parent;
        vector<int> rank;

    public:
        DSU(int n): n(n){
            parent = vector<int>(n);

            for(int i = 0; i < n; i++)
                parent[i] = i;
        }

        void make_set(int v){
            if(v > n || v == 0) return;
            parent[v] = v;
        }

        // The value of parent[parent[v]] is assigned to parent[v] after the find_set(parent[v]) function call is completed
        // which is again completed after recursively calling find_set(parent[parent[v]]) which does the assignment of even higher parent...
        // This implementation is then optimized in such a way so as to completely improve the coplexity of find_set() function...
        // All the nodes are then directly pointing to the root of the tree.
        int find_set(int v){
            if(v == parent[v]) 
                return v; 

            return parent[v] = find_set(parent[v]);
        }

        void union_set(int a, int b){
            
        }

};


int main(){
    
    int n;
    cin >> n;

    DSU dsu = DSU(n);



    cout << endl << "The above is the implementation of Disjoint Set Union class";
    return 0;
}
