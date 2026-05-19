/**
 * @problem: Merge Sorted Array
 * @time_complexity: O(m + n) - We iterate through both arrays exactly once.
 * @space_complexity: O(1) - We merge in-place inside nums1.
 * @explanation: We use Three Pointers starting from the back.
 * p1 points to the last actual element of nums1.
 * p2 points to the last element of nums2.
 * p points to the very last empty slot of nums1.
 * We repeatedly place the largest element at p, guaranteeing we never 
 * overwrite an element in nums1 before we evaluate it.
 */

#include <iostream>
#include <vector>

auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int p1 = m - 1;         // Pointer for valid elements in nums1
        int p2 = n - 1;         // Pointer for nums2
        int p = m + n - 1;      // Pointer for the final merged array (end of nums1)
        
        // While there are still elements to compare in both arrays
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }
        
        // Edge Case: If nums2 still has elements left, copy them over.
        // (If nums1 has elements left, we don't do anything because they 
        // are already sitting in their correct sorted positions at the front!)
        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
    }
};

int main() {
    Solution sol;
    
    // Setup Test Case
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    std::vector<int> nums2 = {2, 5, 6};
    int n = 3;
    
    sol.merge(nums1, m, nums2, n);
    
    // Print Output
    std::cout << "Merged Array: [ ";
    for (int num : nums1) {
        std::cout << num << " ";
    }
    std::cout << "]\n";
    
    return 0;
}
