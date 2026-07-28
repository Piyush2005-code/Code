#include<iostream>


using namespace std;

// The current implementation is only for the range queries of sum of segments of array.
class segmentTree{
    private:
        int *t;
        int n;

    public:
        // Initialize with the number of nodes in the original array...
        segmentTree(int _n) : n(_n){
            t = new int[4 * n];
            for(int i = 0; i < 4 * n; i++) t[i] = 0;
        }
        
        void build(int a[], int v, int l, int r){
            if(l == r){
                t[v] = a[l];
            } else {
                int m = l + (r - l) / 2;
                build(a, v * 2 + 1, l, m);
                build(a, v * 2 + 2, m + 1, r);
                t[v] = t[v * 2 + 1] + v[v * 2 + 2];
            }
        }

        int sum()
};


int main(){



}
