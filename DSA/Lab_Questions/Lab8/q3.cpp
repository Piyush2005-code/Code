// In the ancient city of Arbor, the Great Registry keeps records of every citizen’s secret gate key (a positive number). The Registry stores these keys on shelves built exactly like a B-tree, that is, strong, balanced, and efficient, so the Gatekeeper can quickly answer questions.
// One stormy night, the Gatekeeper receives a peculiar request: given a number K (a test key), report the closest smaller key in the registry (the predecessor) and the closest larger key (the successor). If either does not exist, the Gatekeeper must return -1 for that side.
// Your job is to help the Gatekeeper: build the B-tree of minimum degree t (insert the given keys in order) and then answer exactly one query for the predecessor and successor of K.

// In programming context, 
// Given n distinct keys and a B-tree minimum degree t:
// Insert the n keys (in the given insertion order) into an initially empty B-tree.
// For an integer K, print:
// the predecessor: the largest key strictly less than K, or -1 if none exists.
// the successor: the smallest key strictly greater than K, or -1 if none exists.
// Both values printed on a single line separated by a space: pred succ.

// Constraints:
// n - number of keys to insert (0 <= n <= 1000).
// t - minimum degree of the B-tree (integer >= 2).

// Sample Input:
// 6 3
// 10 20 5 6 12 30
// 12
// Output:
// 10 20


#include <bits/stdc++.h>
using namespace std;

// -------------------- BTreeNode --------------------
class BTreeNode {
public:
    int t;
    vector<int> keys;
    vector<BTreeNode*> C;
    bool leaf;

    BTreeNode(int _t, bool _leaf) : t(_t), leaf(_leaf) {}

    int findKeyIndex(int k) {
        int idx = 0;
        while (idx < (int)keys.size() && keys[idx] < k)
            idx++;
        return idx;
    }

    // Insert into non-full node
    void insertNonFull(int k) {
        int i = (int)keys.size() - 1;

        if (leaf) {
            // Insert key in sorted order
            keys.push_back(0);
            while (i >= 0 && keys[i] > k) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = k;
        } else {
            // Move to appropriate child
            while (i >= 0 && keys[i] > k)
                i--;
            i++;
            if ((int)C[i]->keys.size() == 2 * t - 1) {
                splitChild(i, C[i]);
                if (k > keys[i])
                    i++;
            }
            C[i]->insertNonFull(k);
        }
    }

    // Split full child y at index i
    void splitChild(int i, BTreeNode* y) {
        BTreeNode* z = new BTreeNode(y->t, y->leaf);
        int t = y->t;

        // Move last (t-1) keys from y to z
        for (int j = 0; j < t - 1; j++)
            z->keys.push_back(y->keys[j + t]);

        // Move children
        if (!y->leaf) {
            for (int j = 0; j < t; j++)
                z->C.push_back(y->C[j + t]);
        }

        // Resize y
        y->keys.resize(t - 1);
        if (!y->leaf)
            y->C.resize(t);

        // Insert z into children of current node
        C.insert(C.begin() + i + 1, z);
        // Insert median key into this node
        keys.insert(keys.begin() + i, y->keys[t - 1]);
    }

    // Find predecessor of k
    pair<bool, int> predecessor(int k) {
        int idx = findKeyIndex(k);

        // Case 1: found key == k
        if (idx < (int)keys.size() && keys[idx] == k) {
            // If left child exists, find rightmost key of that subtree
            if (!leaf) {
                BTreeNode* cur = C[idx];
                while (!cur->leaf)
                    cur = cur->C.back();
                return {true, cur->keys.back()};
            } else {
                // If no smaller key in this node, check previous key
                if (idx > 0)
                    return {true, keys[idx - 1]};
                else
                    return {false, -1};
            }
        }

        // Case 2: key not found in this node
        if (leaf) {
            if (idx > 0)
                return {true, keys[idx - 1]};
            else
                return {false, -1};
        }

        // Recurse in appropriate child
        auto p = C[idx]->predecessor(k);
        if (p.first)
            return p;
        // If no predecessor in subtree, take previous key (if exists)
        if (idx > 0)
            return {true, keys[idx - 1]};
        return {false, -1};
    }

    // Find successor of k
    pair<bool, int> successor(int k) {
        int idx = findKeyIndex(k);

        // Case 1: found key == k
        if (idx < (int)keys.size() && keys[idx] == k) {
            // If right child exists, find leftmost key of that subtree
            if (!leaf) {
                BTreeNode* cur = C[idx + 1];
                while (!cur->leaf)
                    cur = cur->C.front();
                return {true, cur->keys.front()};
            } else {
                // If there’s a next key in the node
                if (idx + 1 < (int)keys.size())
                    return {true, keys[idx + 1]};
                else
                    return {false, -1};
            }
        }

        // Case 2: key not found in this node
        if (leaf) {
            if (idx < (int)keys.size())
                return {true, keys[idx]};
            else
                return {false, -1};
        }

        // Recurse in appropriate child
        auto s = C[idx]->successor(k);
        if (s.first)
            return s;
        // If no successor in subtree, take current key (if exists)
        if (idx < (int)keys.size())
            return {true, keys[idx]};
        return {false, -1};
    }
};

// -------------------- BTree --------------------
class BTree {
public:
    BTreeNode* root;
    int t;

    BTree(int _t) : root(nullptr), t(_t) {}

    void insert(int k) {
        if (root == nullptr) {
            root = new BTreeNode(t, true);
            root->keys.push_back(k);
            return;
        }

        if ((int)root->keys.size() == 2 * t - 1) {
            BTreeNode* s = new BTreeNode(t, false);
            s->C.push_back(root);
            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->C[i]->insertNonFull(k);
            root = s;
        } else {
            root->insertNonFull(k);
        }
    }

    pair<bool, int> predecessor(int k) {
        if (!root) return {false, -1};
        return root->predecessor(k);
    }

    pair<bool, int> successor(int k) {
        if (!root) return {false, -1};
        return root->successor(k);
    }
};

// -------------------- MAIN --------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    if (!(cin >> n >> t)) return 0;
    vector<int> keys(n);
    for (int i = 0; i < n; ++i) cin >> keys[i];
    int K; cin >> K;

    BTree tree(t);
    for (int k : keys) tree.insert(k);

    auto p = tree.predecessor(K);
    auto s = tree.successor(K);
    int pred = p.first ? p.second : -1;
    int succ = s.first ? s.second : -1;
    cout << pred << " " << succ << "\n";
    return 0;
}
