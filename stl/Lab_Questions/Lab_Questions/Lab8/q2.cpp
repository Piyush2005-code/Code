// Given a B-tree of order t, insert a sequence of integers and output the height of the resulting B-tree (root is at height 1). Input Format Line 1: n t (number of keys to insert, order of B-tree) Line 2: n space-separated integers (keys to insert in given order) Output Format Single integer representing the height of the B-tree after all insertions. Sample Input/Output Test Case 1 Input: 6 3 8 4 15 20 2 10 Output: 2 #include <iostream>
 #include <vector>
 using namespace std;
 
 // B-Tree Node
 class BTreeNode {
 public:
 vector<int> keys; // keys in the node
 vector<BTreeNode*> children; // child pointers
 int t; // minimum degree
 bool leaf; // true if leaf
 
 BTreeNode(int degree, bool isLeaf) {
 t = degree;
 leaf = isLeaf;
 keys.reserve(2 * t - 1);
 if (!leaf) children.reserve(2 * t);
 }
 
 // TODO: Insert key into non-full node
 void insertNonFull(int key) {
 // Implement insertion logic for non-full node
 }
 
 // TODO: Split a full child node
 void splitChild(int i, BTreeNode* fullChild) {
 // Implement splitting of fullChild at index i
 }
 };
 
 // B-Tree wrapper
 class BTree {
 public:
 BTreeNode* root;
 int t; // minimum degree
 
 BTree(int degree) {
 root = nullptr;
 t = degree;
 }
 
 // TODO: Insert a key into the B-tree
 void insert(int key) {
 // Handle root splitting if needed and call insertNonFull
 }
 
 // Get height of the B-tree
 int getHeight() {
 if (root == nullptr) return 0;
 return calculateHeight(root);
 }
 
 private:
 // Recursive helper to calculate height from a given node
 int calculateHeight(BTreeNode* node) {
 if (node->leaf) return 1;
 // TODO: return 1 + height of any child (all children at same level)
 }
 };
 
 int main() {
 int n, t;
 cin >> n >> t;
 
 BTree* btree = new BTree(t);
 
 // Insert n keys
 for (int i = 0; i < n; i++) {
 int key;
 cin >> key;
 btree->insert(key);
 }
 
 // Output height of the B-tree
 cout << btree->getHeight() << endl;
 
 return 0;
 }