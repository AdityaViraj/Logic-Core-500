/**
 * @problem: Container With Most Water
 * @time_complexity: O(N) - We scan the array exactly once.
 * @space_complexity: O(1) - Only a few integer variables are used.
 * @explanation: We use the Two Pointer technique from opposite ends to maximize width.
 * The height of the water is bottlenecked by the shorter line. 
 * Since moving any pointer decreases the width, we must always move the pointer 
 * pointing to the shorter line, as that is the only mathematical way to potentially 
 * increase the container's total height and compensate for the lost width.
 */

#include <iostream>
#include <vector>
#include <algorithm> // For std::max and std::min

auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;
        
        while (left < right) {
            // Calculate current area
            int current_width = right - left;
            int current_height = std::min(height[left], height[right]);
            int current_area = current_width * current_height;
            
            // Store the maximum area found so far
            max_area = std::max(max_area, current_area);
            
            // THE OBSERVATION: Always throw away the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_area;
    }
};

int main() {
    Solution sol;
    
    // Test Case: Should output 49 (from height 7 and 7 at width 7)
    std::vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    
    std::cout << "Maximum Water Area: " << sol.maxArea(heights) << "\n";
    
    return 0;
}
