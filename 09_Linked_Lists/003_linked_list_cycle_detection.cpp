/**
 * PROBLEM 003: Linked List Cycle Detection
 * =========================================================================
 * 🧠 THE LOGICAL MEMORY MAP (TORTOISE AND HARE):
 * =========================================================================
 * 1. If a list is straight, the 'fast' pointer will hit 'nullptr' and stop.
 * 2. If there is a cycle, the 'fast' pointer enters the loop and starts 
 * "lapping" the 'slow' pointer. 
 * 3. Because 'fast' is moving exactly 1 unit of speed faster than 'slow' 
 * relative to the loop, it will eventually close the gap and they will occupy 
 * the exact same memory address.
 * =========================================================================
 * 🚀 COMPLEXITY ANALYSIS:
 * =========================================================================
 * - Time Complexity: O(N) -> Single pass traversal.
 * - Space Complexity: O(1) -> Zero extra memory; purely pointer manipulation.
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        // Keep moving as long as the fast pointer hasn't hit the end of the line
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;        // Move slow by 1 step
            fast = fast->next->next;  // Move fast by 2 steps

            // Collision Check: If they meet, they are trapped in a cycle
            if (slow == fast) {
                return true;
            }
        }

        // If the loop finishes, fast reached the end -> No cycle exists
        return false;
    }
};

int main() {
    // Systems Style: Manual allocation for cycle testing
    ListNode* head = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node0 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    head->next = node2;
    node2->next = node0;
    node0->next = node4;
    node4->next = node2; // Creates a cycle back to node 2

    Solution sol;
    if (sol.hasCycle(head)) {
        std::cout << "Cycle detected in memory layout!\n";
    } else {
        std::cout << "No cycle detected.\n";
    }

    // Cleanup: Be careful not to delete nodes twice if there is a cycle!
    // In a real system, you'd break the cycle first before deleting nodes.
    node4->next = nullptr; 
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* temp = curr->next;
        delete curr;
        curr = temp;
    }

    return 0;
}
