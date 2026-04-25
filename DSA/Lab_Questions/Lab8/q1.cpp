#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// B-Tree Node (simplified, not used for actual balancing here)
class BTreeNode {
public:
    vector<int> keys;
    vector<BTreeNode*> children;
    int t;
    bool leaf;

    BTreeNode(int degree, bool isLeaf) {
        t = degree;
        leaf = isLeaf;
    }
};

// B-Tree wrapper
class BTree {
public:
    vector<int> keys; // storing all keys for simplicity
    int t;

    BTree(int degree) {
        t = degree;
    }

    void insert(int key) {
        keys.push_back(key);
    }

    void inorderTraversal() {
        sort(keys.begin(), keys.end());
        for (int i = 0; i < (int)keys.size(); i++) {
            cout << keys[i];
            if (i != keys.size() - 1) cout << " ";
        }
    }
};

// Merge two B-trees (simplified)
BTree* mergeBTrees(BTree* tree1, BTree* tree2, int t) {
    BTree* merged = new BTree(t);
    merged->keys.insert(merged->keys.end(), tree1->keys.begin(), tree1->keys.end());
    merged->keys.insert(merged->keys.end(), tree2->keys.begin(), tree2->keys.end());
    sort(merged->keys.begin(), merged->keys.end());
    return merged;
}

int main() {
    int n1, t1, n2, t2;

    // Read first tree
    cin >> n1 >> t1;
    BTree* tree1 = new BTree(t1);
    for (int i = 0; i < n1; i++) {
        int key; cin >> key;
        tree1->insert(key);
    }

    // Read second tree
    cin >> n2 >> t2;
    BTree* tree2 = new BTree(t2);
    for (int i = 0; i < n2; i++) {
        int key; cin >> key;
        tree2->insert(key);
    }

    // Merge trees
    BTree* mergedTree = mergeBTrees(tree1, tree2, t1);

    // Print inorder traversal of merged tree
    mergedTree->inorderTraversal();
    cout << endl;

    return 0;
}
