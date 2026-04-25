/*#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Comparator for min-heap
struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;  // min-heap
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for (auto l : lists) {
            if (l) pq.push(l);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            tail->next = node;
            tail = tail->next;

            if (node->next) pq.push(node->next);
        }

        return dummy.next;
    }
};

int main() {
    int k;
    cin >> k;
    vector<ListNode*> lists(k);

    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            ListNode* newNode = new ListNode(x);
            if (!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
        }
        lists[i] = head;
    }

    Solution sol;
    ListNode* merged = sol.mergeKLists(lists);

    while (merged) {
        cout << merged->val << " ";
        merged = merged->next;
    }
    cout << "\n";
    return 0;
}
*/

//Solution:
#include <iostream>
using namespace std;

// Definition for a doubly linked list node.
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to insert a node at the end of the doubly linked list.
void insert(Node*& head, int data) {
    // Complete this function.
    if(head == NULL) head = new Node(val);
    else{
        Node* temp = head;
        Node* newNode = new Node(val);
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to delete all occurrences of a key if it appears at least twice in the doubly linked list.
void deleteIfOccursTwice(Node*& head, int key) {
    // Complete this function.

}

// Function to print the doubly linked list.
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int n; cin >> n;
    Node* head = nullptr;
    for(int i=0; i<n; i++){
        int t; cin >> t;
        insert(head, t);
    }

    int key; cin >> key;
    deleteIfOccursTwice(head, key);

    printList(head);

    return 0;
}