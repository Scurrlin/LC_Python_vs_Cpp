#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS(nums.size(), 1);

        for (int i = nums.size() - 1; i >= 0; --i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] < nums[j]) {
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
                }
            }
        }
        
        return *max_element(LIS.begin(), LIS.end());
    }
};

// Runtime1: 86ms, beats 52.80%
// Memory1: 13.17MB, beats 70.79%

// Runtime2: 87ms, beats 52.03%
// Memory2: 13.23MB, beats 52.96%

// Runtime3: 88ms, beats 51.29%
// Memory3: 13.16MB, beats 70.79%

// Runtime reduced by a factor of 10 to not skew data visualization