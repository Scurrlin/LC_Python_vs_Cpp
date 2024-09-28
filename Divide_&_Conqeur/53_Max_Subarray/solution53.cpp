#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int total = 0;

        for (int n : nums) {
            total += n;
            res = max(res, total);
            if (total < 0) {
                total = 0;
            }
        }
        
        return res;
    }
};

// Runtime1: 75ms, beats 66.44%
// Memory1: 70.59MB, beats 72.71%

// Runtime2: 70ms, beats 85.40%
// Memory2: 70.38MB, beats 98.78%

// Runtime3: 72ms, beats 78.25%
// Memory3: 70.59MB, beats 72.71%

// Runtime reduced by a factor of 10 to not skew data visualization