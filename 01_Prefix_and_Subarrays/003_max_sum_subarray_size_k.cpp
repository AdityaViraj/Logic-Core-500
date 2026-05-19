/**
 * PROBLEM 03: Maximum Sum Subarray of Size K
 * * * CORE LOGIC (Sliding Window Optimization):
 * Instead of recalculating the sum of K consecutive elements from scratch at every position,
 * we reuse the previous window's sum. When the window shifts right:
 * 1. The leftmost element falls out of the window (Subtract it).
 * 2. A new element enters from the right (Add it).
 * * * PROOF OF SPEED:
 * - Brute Force: Recomputing every window takes O(N * K).
 * - Sliding Window: Reuses the middle values. Each element is added once and subtracted once.
 * Total operations drop to exactly O(N), ensuring a clean pass on Codeforces.
 * * * COMPLEXITY:
 * - Time: O(N) single-pass sweep.
 * - Space: O(1) continuous scalar variables.
 */

#include <iostream>
#include <vector>
#include <algorithm> // For std::max

// Fast I/O for Competitive Programming
auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maximumSumSubarray(int k, std::vector<int>& arr) {
        int n = arr.size();
        if (n < k) return 0; // Guard clause for invalid inputs

        int window_sum = 0;
        int max_sum = 0;

        // Step 1: Compute the sum of the absolute first window of size K
        for (int i = 0; i < k; i++) {
            window_sum += arr[i];
        }
        max_sum = window_sum;

        // Step 2: Slide the window across the remaining layout
        for (int i = k; i < n; i++) {
            // "i" is the incoming index, "i - k" is the index exiting on the left side
            window_sum = window_sum + arr[i] - arr[i - k];
            
            // Check if the newly updated subsegment sum breaks our old record
            max_sum = std::max(max_sum, window_sum);
        }

        return max_sum;
    }
};

int main() {
    Solution sol;
    
    // Sample Test Context
    std::vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    
    std::cout << "Maximum Sum Subarray of size " << k << " is: " 
              << sol.maximumSumSubarray(k, arr) << "\n";
              
    return 0;
}
