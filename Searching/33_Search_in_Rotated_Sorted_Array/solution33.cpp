#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1;
        
        while (L <= R) {
            int mid = L + (R - L) / 2; // To avoid potential overflow
            
            if (nums[mid] == target) {
                return mid;
            }
            
            // Check if the left half is sorted
            if (nums[L] <= nums[mid]) {
                // Target is in the right half or outside the left range
                if (target > nums[mid] || target < nums[L]) {
                    L = mid + 1;
                } else {
                    R = mid - 1;
                }
            } 
            // Otherwise, the right half must be sorted
            else {
                // Target is in the left half or outside the right range
                if (target < nums[mid] || target > nums[R]) {
                    R = mid - 1;
                } else {
                    L = mid + 1;
                }
            }
        }
        
        return -1; // Target not found
    }
};

// Time Complexity: O(logN)
// Space Complexity: O(1)

// Runtime1: 0ms, beats 100%
// Runtime2: 13.98MB, beats 50.38%