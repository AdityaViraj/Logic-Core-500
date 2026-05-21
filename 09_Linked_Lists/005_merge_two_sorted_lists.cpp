/**
 * PROBLEM 005: Merge Two Sorted Lists
 * =========================================================================
 * 🧠 THE LOGICAL MEMORY MAP (THE DUMMY NODE PATTERN):
 * =========================================================================
 * 1. We want to weave two lists together in-place (O(1) space). We do not 
 * create any new data nodes using 'new'. We just rewire the existing arrows.
 * 2. THE TRICK: Managing the very first node of a merged list is always messy 
 * due to null checks. We bypass this by creating a fake "Dummy Node". 
 * We build our merged list attached to this dummy.
 * 3. In Systems C++, we allocate the dummy node on the STACK (without 'new').
 * This means when the function finishes, the dummy node is automatically 
 * destroyed by the computer, leaving zero memory leaks, and we simply 
 * return 'dummy.next' as our real head!
 * =========================================================================
 * 🚀 COMPLEXITY ANALYSIS:
 * =========================================================================
 * - Time Complexity: O(N + M) -> We visit each node from both lists exactly once.
 * - Space Complexity: O(1) -> Rewiring existing nodes, no heap allocation.
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // SYSTEMS TRICK: Stack allocation. This node will automatically vanish 
        // when the function returns. No 'new', no 'delete' needed!
        ListNode dummy(0); 
        
        // 'tail' is the pointer we use to build our zipper.
        ListNode* tail = &dummy; 

        // Zipper Phase: Compare the fronts of both lists
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1; // Point to list1's node
                list1 = list1->next; // Move list1 forward
            } else {
                tail->next = list2; // Point to list2's node
                list2 = list2->next; // Move list2 forward
            }
            tail = tail->next; // Move our zipper tail forward
        }

        // Leftover Phase: One of the lists might still have remaining nodes.
        // Because they are already sorted, we just attach the rest of the chain!
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        // Return the actual start of the merged list, ignoring our fake stack dummy
        return dummy.next;
    }
};

// Helper function to print lists
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        std::cout << curr->val << " -> ";
        curr = curr->next;
    }
    std::cout << "nullptr\n";
}

int main() {
    // Setup List 1: 1 -> 2 -> 4
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    // Setup List 2: 1 -> 3 -> 4
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    std::cout << "List 1: "; printList(l1);
    std::cout << "List 2: "; printList(l2);

    Solution sol;
    ListNode* merged_head = sol.mergeTwoLists(l1, l2);

    std::cout << "Merged: "; printList(merged_head);

    // Cleanup: The nodes are now intertwined. We just delete from the merged head!
    ListNode* curr = merged_head;
    while (curr != nullptr) {
        ListNode* temp = curr->next;
        delete curr;
        curr = temp;
    }

    return 0;
}
