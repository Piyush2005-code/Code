// Insertion in BTrees.

// Define the required functions for performing an insertion in a BTree.

// Input Format:
// First line contains two integers n and m denoting the number of insertions to be made and the order of the BTree.
// The next line contains n - integers, the keys to be inserted in the BTree

// Output Format:
// Print the traversal of the BTree after all the insertions are done.

// Sample Input:
// 5 3
// 5 3 2 4 1

// Sample Output:
// 1 2 3 4 5

#include <iostream>
using namespace std;

// =================== BTree Node ===================
class BTreeNode {
    int *keys;           // Array of keys
    int t;               // Minimum degree
    BTreeNode **C;       // Array of child pointers
    int n;               // Current number of keys
    bool leaf;           // True if leaf node
public:
    BTreeNode(int _t, bool _leaf);

    void insertNonFull(int k);
    void splitChild(int i, BTreeNode *y);
    void traverse();
    BTreeNode *search(int k);

    friend class BTree;
};

// =================== BTree ===================
class BTree {
    BTreeNode *root;
    int t;
public:
    BTree(int _t) { root = NULL; t = _t; }

    void traverse() { if (root != NULL) root->traverse(); }
    BTreeNode* search(int k) { return (root == NULL) ? NULL : root->search(k); }
    void insert(int k);
};

// =================== BTreeNode Constructor ===================
BTreeNode::BTreeNode(int t1, bool leaf1) {
    t = t1;
    leaf = leaf1;
    keys = new int[2 * t - 1];
    C = new BTreeNode *[2 * t];
    n = 0;
}

// =================== Traverse (Given) ===================
void BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (leaf == false)
            C[i]->traverse();
        cout << keys[i] << " ";
    }
    if (leaf == false)
        C[i]->traverse();
}

// =================== Split Child ===================
void BTreeNode::splitChild(int i, BTreeNode *y) {
    // Create a new node z to store (t-1) keys of y
    BTreeNode *z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;

    // Copy last (t-1) keys of y to z
    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    // Copy children if not leaf
    if (!y->leaf) {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }

    // Reduce number of keys in y
    y->n = t - 1;

    // Create space for new child
    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];

    // Link new child
    C[i + 1] = z;

    // Move one key from y to this node
    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[t - 1];
    n++;
}

// =================== Insert Non-Full ===================
void BTreeNode::insertNonFull(int k) {
    int i = n - 1;

    if (leaf) {
        // Insert key into this node
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
        n++;
    } else {
        // Find child to insert into
        while (i >= 0 && keys[i] > k)
            i--;
        i++;

        // Split child if full
        if (C[i]->n == 2 * t - 1) {
            splitChild(i, C[i]);
            if (keys[i] < k)
                i++;
        }
        C[i]->insertNonFull(k);
    }
}

// =================== Insert ===================
void BTree::insert(int k) {
    if (root == NULL) {
        root = new BTreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    } else {
        if (root->n == 2 * t - 1) {
            BTreeNode *s = new BTreeNode(t, false);
            s->C[0] = root;
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
}

// =================== Main ===================
int main() {
    int n, m;
    cin >> n >> m;

    BTree t(m);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        t.insert(a);
    }

    t.traverse();
    return 0;
}
