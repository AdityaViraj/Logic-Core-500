/**
 * @problem: Range Sum Query - Immutable
 * @time_complexity: O(N) to build, O(1) per query.
 * @space_complexity: O(N) to store the prefix sums.
 * @explanation: We pre-calculate a 'prefix sum' array where each index i 
 * contains the total sum of nums[0...i]. To find the range [L, R], 
 * we simply subtract the sum up to (L-1) from the sum up to R.
 */

#include <iostream>
#include <vector>

auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class NumArray {
private:
    std::vector<int> prefix;

public:
    // Pre-calculation (O(N))
    NumArray(std::vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n + 1, 0); // Using n+1 to handle index 0 edge case easily
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    // O(1) Query
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

int main() {
    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray sol(nums);
    
    // Querying range [0, 2] -> -2 + 0 + 3 = 1
    std::cout << "Sum [0, 2]: " << sol.sumRange(0, 2) << "\n";
    // Querying range [2, 5] -> 3 + -5 + 2 + -1 = -1
    std::cout << "Sum [2, 5]: " << sol.sumRange(2, 5) << "\n";
    
    return 0;
}
