/*
In a city traffic monitoring system, vehicle speeds are continuously being recorded. To analyze traffic flow, the system must quickly determine the median speed of all vehicles currently stored. You are required to build a program that maintains a dynamic set of integers (the vehicle speeds). The system should support three types of operations:
Insert a speed into the system.
Delete a speed from the system (if it exists).
Query the current median speed of all stored values.
The median is defined as:
If the number of elements is odd :the middle element after sorting.
If the number of elements is even : the bigger of the two middle elements.

If a median query is made when the system has no data, output -1.
If a delete operation is given for a speed that does not exist in the system, simply ignore it.
 Input Format
The first line contains an integer Q, the number of queries.
Each of the next Q lines contains one of the following commands:
1 x : Insert the value x.
2 x : Delete the value x (if present)
3 : Print the current median.

Output Format
For every query of type 3, print the current median (or -1 if no values exist).

Sample Input:
9
1 100
1 200
3
1 300
3
2 200
3
2 100
3

Output:
200
200
300
300
*/

//Solution: 
#include <stdio.h>
#include <stdlib.h>

// -------- AVL Node Definition --------
struct Node {
    int key;
    int height;
    int size;
    struct Node *left, *right;
};

// -------- Utility Functions (already implemented) --------
int height(struct Node* n) { return n ? n->height : 0; }
int size(struct Node* n) { return n ? n->size : 0; }

void update(struct Node* n) {
    if (n) {
        int hl = height(n->left);
        int hr = height(n->right);
        n->height = (hl > hr ? hl : hr) + 1;
        n->size = size(n->left) + size(n->right) + 1;
    }
}

// --------- TODO: Rotations (to be implemented by students) ---------
struct Node* rotateRight(struct Node* y) {
    // TODO: Implement right rotation
    struct Node* temp = 
}

struct Node* rotateLeft(struct Node* x) {
    // TODO: Implement left rotation
}

// --------- TODO: Balance function ---------
struct Node* balance(struct Node* n) {
    // TODO: Update node, calculate balance factor
    // Perform necessary rotations
}

// --------- TODO: Insertion ---------
struct Node* insert(struct Node* root, int key) {
    // TODO: Implement AVL insertion using recursion + balance()
}

// --------- TODO: Deletion ---------
struct Node* erase(struct Node* root, int key) {
    // TODO: Implement AVL deletion (use minValueNode for successor)
}

// --------- Order Statistic (already implemented) ---------
int getKth(struct Node* root, int k) {
    if (!root || k <= 0 || k > size(root)) return -1;
    int leftSize = size(root->left);
    if (k == leftSize + 1) return root->key;
    else if (k <= leftSize) return getKth(root->left, k);
    else return getKth(root->right, k - leftSize - 1);
}

// -------- Driver Code (given) --------
int main() {
    int Q;
    scanf("%d", &Q);
    struct Node* root = NULL;

    while (Q--) {
        int type, x;
        scanf("%d", &type);
        if (type == 1) { // insert
            scanf("%d", &x);
            root = insert(root, x);
        } else if (type == 2) { // delete
            scanf("%d", &x);
            root = erase(root, x);
        } else if (type == 3) { // median
            if (size(root) == 0) {
                printf("-1\n");
            } else {
                int n = size(root);
                int median;
                if (n % 2 == 1) {
                    median = getKth(root, (n + 1) / 2); // odd → middle
                } else {
                    median = getKth(root, n / 2 + 1);   // even → upper middle
                }
                printf("%d\n", median);
            }
        }
    }
    return 0;
}