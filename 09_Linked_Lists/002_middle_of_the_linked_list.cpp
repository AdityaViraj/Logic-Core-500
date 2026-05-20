/**
 * PROBLEM 002: Middle of the Linked List
 * =========================================================================
 * 🧠 THE LOGICAL MEMORY MAP (TORTOISE AND HARE):
 * =========================================================================
 * 1. Nodes are scattered non-contiguously in heap memory. To find the midpoint 
 * in a single pass, we use two pointers traveling at different speeds.
 * 2. 'slow' pointer steps forward by 1 node per iteration.
 * 3. 'fast' pointer steps forward by 2 nodes per iteration.
 * 4. Since 'fast' moves twice as fast as 'slow', the moment 'fast' hits the 
 * end of the list (nullptr or last node), 'slow' is mathematically 
 * guaranteed to be sitting precisely on the midpoint node.
 * =========================================================================
 * 🚀 COMPLEXITY ANALYSIS:
 * =========================================================================
 * - Time Complexity: O(N) -> Single pass optimization.
 * - Space Complexity: O(1) -> Only uses two tracking scalar pointers.
 */

#include <iostream>

// Low-level representation of a structural node in system RAM
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Ensure both fast and fast->next are valid before jumping 2 steps ahead.
        // This safe-guard prevents segmentation faults on null address reads.
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;       // Moves 1 step
            fast = fast->next->next; // Moves 2 steps
        }

        // 'slow' is now pointing precisely to the middle node segment
        return slow;
    }
};

// Helper function to print values starting from a given node address
void printListFromNode(ListNode* startNode) {
    ListNode* curr = startNode;
    while (curr != nullptr) {
        std::cout << curr->val << " -> ";
        curr = curr->next;
    }
    std::cout << "nullptr\n";
}

int main() {
    // Systems Style: Manual object allocation on the heap layout
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Full Linked List Layout: ";
    printListFromNode(head);

    Solution sol;
    ListNode* middle = sol.middleNode(head);

    std::cout << "List Layout Starting from Middle Node: ";
    printListFromNode(middle);

    // Systems Style Cleanup: Free all allocated nodes to keep memory footprint clear
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* temp = curr->next;
        delete curr;
        curr = temp;
    }

    return 0;
}
