/*
In the magical kingdom of Linkedoria, there exist k ancient scrolls, each inscribed by a different royal scribe. Every scroll contains a sacred sequence of numbers written in ascending order, representing power levels of enchanted spells. These scrolls are to be presented at the Grand Council of Merge, where the Supreme Mage will combine all spells into a single, strictly ordered scroll. Only then can the kingdom defend itself against the impending chaos of the Data Demons.

However, there’s a twist. The scrolls are cursed:

You can only read each scroll from start to end, one spell at a time.
You cannot rearrange any spell within a scroll.
At any time, you may only compare the current spell at the top of each scroll.
You must construct a new scroll, placing spells one-by-one in perfectly increasing order of power.

If you misplace even one spell, the entire kingdom collapses into a segmentation fault.
Example: 

scrolls = [
[1 -> 4-> 5],
[1 -> 3 -> 4],
[2 -> 6]
]

Final Spell:
[1->1->2->3->4->4->5->6]

Sample input:
3
3 1 4 5
3 1 3 4
2 2 6

where line 1 is number of scrolls (here 3). Line 2 is number of spells in a scroll 1 followed by the spells. Goes on till the last spell.

Expected Output:
1 1 2 3 4 4 5 6
*/

//Solution Template:
#include <iostream>
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

// TODO: Define comparator for priority_queue
struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        // Implement comparator logic
        return false; 
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // TODO: Implement merge logic using min-heap
        return nullptr; 
    }
};

int main() {
    // TODO: Take input for k linked lists
    // TODO: Call mergeKLists and print the merged list
    return 0;
}