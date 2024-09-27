#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            
            if (nums[m] > target) {
                r = m - 1;
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                return m;
            }
        }
        
        return -1;
    }
};

// Time Complexity:
// Space Complexity:

// Runtime1: 22ms, beats 86.36%
// Memory1: 30.22MB, beats 23.48%

// Runtime2: 26ms, beats 62.49%
// Memory2: 30.27MB, beats 23.48%

// Runtime3: 15ms, beats 98.50%
// Memory3: 30.20MB, beats 73.73%