#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;
        
        // Iterate from the second-to-last element to the start
        for (int i = nums.size() - 2; i >= 0; --i) {
            // Check if the current index can reach or exceed the goal
            if (i + nums[i] >= goal) {
                goal = i; // Update the goal
            }
        }
        
        return goal == 0; // Return true if we can reach the start
    }
};
