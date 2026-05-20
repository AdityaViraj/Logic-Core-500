/**
 * PROBLEM 001: Reverse a Singly Linked List
 * =========================================================================
 * 🧠 THE LOGICAL MEMORY MAP:
 * =========================================================================
 * 1. Nodes in a linked list are scattered non-contiguously throughout memory.
 * They are connected only by explicit address pointers (arrows).
 * 2. To reverse it in-place, we do NOT change or copy data values. We leave 
 * the memory blocks exactly where they are and flip the address references backward!
 * 3. To flip an arrow without breaking the chain and dropping the rest of the 
 * list from system memory, we track 3 positions simultaneously:
 * - curr: The exact node you are standing on right now.
 * - prev: The node right behind you (where curr needs to point its new arrow).
 * - next_node: A backup of the node ahead of you so you don't get lost.
 * =========================================================================
 * 🚀 COMPLEXITY ANALYSIS:
 * =========================================================================
 * - Time Complexity: O(N) -> Single sequential pass through the list.
 * - Space Complexity: O(1) -> Pure pointer reassignment, zero extra heap allocations.
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;     // Initially, nothing is behind the head
        ListNode* curr = head;        // Start tracking from the head node
        ListNode* next_node = nullptr; // Temporary pointer backup holder

        while (curr != nullptr) {
            // Step 1: Secure our path forward before clipping the link
            next_node = curr->next;

            // Step 2: Flip the current node's arrow backward to point to history
            curr->next = prev;

            // Step 3: Shift the entire 3-pointer tracking window forward by one slot
            prev = curr;
            curr = next_node;
        }

        // When curr hits nullptr, prev is left standing on the brand new head!
        return prev;
    }
};

// Helper function to iterate and print data straight from memory addresses
void printList(ListNode* head) {
    ListNode* curr = head;
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

    std::cout << "Original List Layout: ";
    printList(head);

    Solution sol;
    ListNode* reversed_head = sol.reverseList(head);

    std::cout << "Reversed List Layout: ";
    printList(reversed_head);

    // Systems Style Cleanup: Manually free heap slots to avoid active memory leaks
    ListNode* curr = reversed_head;
    while (curr != nullptr) {
        ListNode* temp = curr->next;
        delete curr;
        curr = temp;
    }

    return 0;
}
