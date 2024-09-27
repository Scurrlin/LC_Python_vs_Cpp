#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1;
        
        while (L <= R) {
            int mid = L + (R - L) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            if (nums[L] <= nums[mid]) {
                if (target > nums[mid] || target < nums[L]) {
                    L = mid + 1;
                } else {
                    R = mid - 1;
                }
            } 
            
            else {
                if (target < nums[mid] || target > nums[R]) {
                    R = mid - 1;
                } else {
                    L = mid + 1;
                }
            }
        }
        
        return -1;
    }
};

// Runtime1: 0ms, beats 100%
// Runtime2: 13.98MB, beats 50.38%

// Runtime2: 3ms, beats 59.58%
// Memory2: 13.90MB, beats 81.89%

// Runtime3: 0ms, beats 100%
// Memory3: 13.88MB, beats, 81.89%