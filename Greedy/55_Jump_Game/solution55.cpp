#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;
        
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }
        
        return goal == 0;
    }
};

// Runtime1: 36ms, beats 88.62%
// Memory1: 51.15MB, beats 42.11%

// Runtime2: 34ms, beats 93.24%
// Memory2: 51.04MB, beats 80.38%

// Runtime3: 38ms, beats 83.90%
// Memory3: 51.11MB, beats 42.11%

// Runtime reduced by a factor of 10 to not skew data visualization