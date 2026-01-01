// In Silver Creek, the Tax Collector keeps a B-tree of citizen incomes (unique integers). Whenever a citizen earns income, their record is inserted into the tree.
// At the end of the year, the Tax Collector needs to quickly answer questions like:
// “What is the total income of all citizens whose incomes lie between L and R (inclusive)?”
// Your task: After inserting all incomes into the B-tree of minimum degree t, compute the range sum of keys in [L, R], that is,
// Given n distinct integers (keys) and a B-tree minimum degree t:
// Insert the n integers in the given order into the B-tree.
// Given two integers L and R, return the sum of all keys between L and R inclusive.
// Constraints:
// n = number of keys (0 <= n <= 1000)
// t = minimum degree (>= 2)

// Sample Input:
// 8 3
// 10 20 5 6 12 30 7 15
// 6 15
// Output:
// 50

#include <bits/stdc++.h>
using namespace std;

class BTreeNode {
public:
    vector<int> keys;
    vector<BTreeNode*> children;
    int t;
    bool leaf;

    BTreeNode(int t, bool leaf);

    // TODO: implement
    void insertNonFull(int k);

    // TODO: implement
    void splitChild(int i, BTreeNode* y);

    // TODO: implement
    long long rangeSumUtil(int L, int R);
};

class BTree {
public:
    BTreeNode* root;
    int t;

    BTree(int t);

    // TODO: implement
    void insert(int k);

    // TODO: implement
    long long rangeSum(int L, int R);
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;
    BTree tree(t);

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        tree.insert(x);
    }

    int L, R;
    cin >> L >> R;

    cout << tree.rangeSum(L, R) << "\n";
    return 0;
}