/**
 * @problem: Two Sum II - Input Array Is Sorted
 * @time_complexity: O(N) - Each element is visited at most once.
 * @space_complexity: O(1) - We only store two pointers.
 * @explanation: Since the array is sorted, we can use the "Two Pointer" 
 * technique. Initialize 'left' at start, 'right' at end.
 * If sum < target, increase left.
 * If sum > target, decrease right.
 * Because we use only two pointers, space complexity is constant O(1).
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
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int current_sum = numbers[left] + numbers[right];

            if (current_sum == target) {
                // Return 1-indexed results
                return {left + 1, right + 1};
            } else if (current_sum < target) {
                left++; // Need a bigger sum
            } else {
                right--; // Need a smaller sum
            }
        }
        return {}; // No solution found
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = sol.twoSum(nums, target);
    std::cout << "Indices: [" << result[0] << ", " << result[1] << "]" << std::endl;

    return 0;
}
