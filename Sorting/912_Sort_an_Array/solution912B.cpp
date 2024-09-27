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

// Runtime2: 100ms, beats 78.70%
// Memory2: 70.41MB, beats 72.60%

// Runtime3: 105ms, beats 77.21%
// Memory3: 70.36MB, beats 78.28%