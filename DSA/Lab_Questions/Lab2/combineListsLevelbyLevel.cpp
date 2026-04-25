/*
10. Given a LL as shown below. It has a list within a list:
1->{3->4->5}->{10->7->8}->5->{11->13}->15
INPUT: first line of input is number of sublists=n
2.n line of inputs conatain:
3. size of  sublist
4. linked list of size sublist

head pointer of each linked list passed to the vector.

Assume that every sub-element of a sub-list is in a new level. Now output the list level-wise. Like:

1->3->10->5->11->15->4->7->13->5->8
*/

//Solution Template:
/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode* sublist;

    ListNode(int x) : val(x), next(nullptr), sublist(nullptr) {}
};

// Function to combine elements of all sublists level by level
ListNode* combineListsLevelByLevel(vector<ListNode*>& subLists) {
    // write your code here
   
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of sub-linked lists: ";
    cin >> n;

    vector<ListNode*> subLists(n, nullptr);

    for (int i = 0; i < n; ++i) {
        int size;
        cin >> size;

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        for (int j = 0; j < size; ++j) {
            int val;
          
            cin >> val;
            current->next = new ListNode(val);
            current = current->next;
        }

        subLists[i] = dummy->next;
    }

    ListNode* combinedHead = combineListsLevelByLevel(subLists);

   
    printList(combinedHead);

    return 0;
}
*/

//Solution:
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to combine elements of all sublists level by level
ListNode* combineListsLevelByLevel(vector<ListNode*>& subLists) {
    // write your code here
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    int key = 0;
    int size = subLists.size();
    while(key < size){
        key = 0;
        for(int i = 0; i < size; i++){
            if(subLists[i] == NULL){
                key++;
            }
            else{
                current->next = new ListNode(subLists[i]->val);
                subLists[i] = subLists[i]->next;
                current = current->next;
            }
        }
    }
    return dummy->next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of sub-linked lists: ";
    cin >> n;

    vector<ListNode*> subLists(n, nullptr);

    for (int i = 0; i < n; ++i) {
        int size;
        cin >> size;

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        for (int j = 0; j < size; ++j) {
            int val;
          
            cin >> val;
            current->next = new ListNode(val);
            current = current->next;
        }

        subLists[i] = dummy->next;
    }

    ListNode* combinedHead = combineListsLevelByLevel(subLists);

   
    printList(combinedHead);

    return 0;
}