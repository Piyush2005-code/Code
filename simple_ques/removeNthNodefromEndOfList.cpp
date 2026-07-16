/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return nullptr;
        int size = 0;
        ListNode* curr = head;
        while(curr){
            size++;
            curr = curr->next;
        }

        if(size == 1) return nullptr;
        if(size == n){
            curr = head;
            head = head->next;
            delete curr;
            return head;
        }
        curr = head;
        int i = 0;
        ListNode* prevNode = nullptr;
        // head->val = size; Just checking things.
        while(i < size - n){
            prevNode = curr;
            curr = curr->next;
            i++;
        }

        if(prevNode) {
            prevNode->next = curr->next;
            delete curr;
        }

        return head;
    }
};
