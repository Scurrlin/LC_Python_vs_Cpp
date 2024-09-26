#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};

// Time Complexity: O(NlogN)
// Space Complexity: O(N)

// Runtime1: 90ms, beats 80.19%
// Memory1: 70.49MB, beats 75.35%

// Runtime2:
// Memory2:

// Runtime3:
// Memory3: