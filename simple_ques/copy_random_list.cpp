#include<iostream>
#include<vector>
#include<unoredered_map>


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         unordered_map<int, Node*> mp;
//         Node* copy_head = new Node(head->val);
//         mp[head->val] = copy_head;
//         Node* curr = head;
//         Node* copy_curr = copy_head;

//         while(curr){
//             if(curr->next){
//                 if(mp.find(curr->next->val) == mp.end()){
//                     copy_curr->next = new Node(curr->next->val);
//                     mp[curr->next->val] = copy_curr->next;
//                 } else {
//                     copy_curr->next = mp[curr->next->val];
//                 }
//             }
//             if(curr->random){
//                 if(mp.find(curr->random->val) == mp.end()){
//                     copy_curr->random = new Node(curr->random->val);
//                     mp[curr->random->val] = copy_curr->random;
//                 } else {
//                     copy_curr->random = mp[curr->random->val];
//                 }
//             }

//             curr = curr->next;
//             copy_curr = copy_curr->next;
//         }
//         return copy_head;
//     }
// };


class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* curr;

        for(curr = head; curr; curr = curr->next){
            mp[curr] = new Node(curr->val);
        }

        for(curr = head; curr; curr = curr->next){
            mp[curr]->random = mp[curr->random]; // The unordered_map is used to map the original node to it's deep copy counterpart, so that is the approach...
            mp[curr]->next = mp[curr->next]; // These two lines are essentially the way of making it such that the original pointer arithmetic is only used to make upv for the new mapping of the deep copy nodes are mapped correctly...
        }

        return mp[head];
    }
};

