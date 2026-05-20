/**
 * PROBLEM 004: Subarray Sum Equals K
 * * =========================================================================
 * 🧠 THE LOGICAL ROADMAP (WALKING ANALOGY):
 * =========================================================================
 * 1. Imagine walking along a path where each element in the array changes 
 * your "Current Altitude" (running total).
 * * 2. At any point, your current altitude is 'right_prefix_sum'. You want to 
 * know if there is a valid slice ending right here that sums up to K.
 * * 3. Math check: if a section of your path sums up to K, then:
 * (Current Altitude) - (Some Past Altitude) == K
 * Rearranging the math gives us our look-back target:
 * (Current Altitude) - K == (Some Past Altitude)
 * * 4. Instead of looking back manually with a nested loop (which costs O(N^2)),
 * we use a Hash Map as an instant radar. It records:
 * Key: Past Altitude  ->  Value: How many times we stood there.
 * =========================================================================
 * We seed our map with prefix_counts[0] = 1. This handles the case where a 
 * subarray starting exactly from index 0 hits a sum of K. Without it, 
 * Current Altitude - K = 0 would register as "not found" in history!
 * * 🚀 TIME COMPLEXITY: O(N) average time (Single-pass hash lookup).
 * 📦 SPACE COMPLEXITY: O(N) memory footprints inside the map registry.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

// Fast I/O for high-performance execution on online judges
auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        // Map structure: [ Historical Running Sum -> Frequency of Occurrence ]
        std::unordered_map<int, int> prefix_counts;
        
        // Base case initialization: Before starting, we are at altitude 0 exactly once
        prefix_counts[0] = 1;
        
        int current_prefix_sum = 0;
        int total_subarrays = 0;
        
        for (int num : nums) {
            // Step 1: Advance our current running sum (Current Altitude)
            current_prefix_sum += num;
            
            // Step 2: Apply our look-back algebraic formula
            int target_prefix = current_prefix_sum - k;
            
            // Step 3: Check memory history without using the modifying [] operator.
            // .find() returns .end() if the target altitude was never visited before.
            if (prefix_counts.find(target_prefix) != prefix_counts.end()) {
                // If it was visited, add the number of times it occurred to our score
                total_subarrays += prefix_counts[target_prefix];
            }
            
            // Step 4: Record this current altitude into memory for future reference
            prefix_counts[current_prefix_sum]++;
        }
        
        return total_subarrays;
    }
};

int main() {
    Solution sol;
    
    // Test Case: Chunks summing to 7 are [3, 4] and [7]
    std::vector<int> nums = {3, 4, 7, 2, -2};
    int k = 7;
    
    std::cout << "Total Subarrays: " << sol.subarraySum(nums, k) << "\n";
    
    return 0;
}
