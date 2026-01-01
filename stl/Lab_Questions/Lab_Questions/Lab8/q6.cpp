// Given a B-Tree of order t, insert a sequence of integers, and then print the number of leaf nodes in the B-Tree.
// Input Format
// First line: n t (number of keys, order of the B-Tree).
// Second line: n space-separated integers (keys to insert in the given order).
// Output Format
// A single integer (the number of leaf nodes in the B-Tree)


// Sample Input
// 6 3
// 10 20 5 6 12 30
// Sample output
// 2

#include <bits/stdc++.h>
using namespace std;

// ---------------- B-Tree Node ----------------
class BTreeNode {
public:
    vector<int> keys;           // Keys in the node
    vector<BTreeNode*> children; // Child pointers
    int t;                       // Minimum degree
    bool leaf;                   // Is leaf?

    BTreeNode(int t, bool leaf) {
        this->t = t;
        this->leaf = leaf;
    }

    // ---------------- TODO ----------------
    // Insert key into non-full node
    void insertNonFull(int k) {
        // STUDENTS: Implement insertion logic here
    }

    // ---------------- TODO ----------------
    // Split child node
    void splitChild(int i, BTreeNode* y) {
        // STUDENTS: Implement split logic here
    }
};

// ---------------- B-Tree Wrapper ----------------
class BTree {
public:
    BTreeNode* root;
    int t;

    BTree(int t) {
        this->t = t;
        root = nullptr;
    }

    void insert(int k) {
        if (!root) {
            root = new BTreeNode(t, true);
            root->keys.push_back(k);
        } else {
            if ((int)root->keys.size() == 2 * t - 1) {
                BTreeNode* s = new BTreeNode(t, false);
                s->children.push_back(root);
                // ---------------- TODO ----------------
                s->splitChild(0, root);
                int i = (s->keys[0] < k) ? 1 : 0;
                s->children[i]->insertNonFull(k);
                root = s;
            } else {
                root->insertNonFull(k);
            }
        }
    }

    // Count leaf nodes
    int countLeafNodes() {
        return countLeafNodesUtil(root);
    }

private:
    int countLeafNodesUtil(BTreeNode* node) {
        if (!node) return 0;
        if (node->leaf) return 1;
        int count = 0;
        for (auto child : node->children)
            count += countLeafNodesUtil(child);
        return count;
    }
};

// ---------------- Main ----------------
int main() {
    int n, t;
    cin >> n >> t;

    BTree tree(t);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tree.insert(x);
    }

    cout << tree.countLeafNodes() << endl;
    return 0;
}