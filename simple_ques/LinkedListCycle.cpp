#include<iostream>


using namespace std;


class ListNode{
    public:
        int val;
        ListNode* next;
        ListNode(int _val) : val(_val), next(nullptr) {}
        ListNode(int _val, ListNode* _next) : val(_val), next(_next) {}
};


class Solution{
    public:
        bool hasCycle(ListNode* head){
            ListNode* curr1 = head;
            ListNode* curr2 = head;
            int i = 0;

            while(curr2){
                curr2 = curr2->next;
                if(i % 2 == 1) curr1 = curr1->next;
                if(curr1 == curr2) return true;
                i++;
            }
            return false;
        }

        void pringList(ListNode* head){
            ListNode* curr = head;
            cout << endl;

            while(curr){
                cout << curr->val << " ";
                curr = curr->next;
            }
        }
};

//
//
// int main(){
//
//     int n;
//     cin >> n;
//
// }
