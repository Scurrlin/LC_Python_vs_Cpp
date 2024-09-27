#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;

        for (int n : nums) {
            int temp = max(n + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        
        return rob2;
    }
};

// Time Complexity:
// Space Complexity:

// Runtime1: 0ms, beats 100%
// Memory1: 9.36MB, beats 87.98%

// Runtime2: 0ms, beats 100%
// Memory2: 9.35MB, beats 87.98%

// Runtime3: 0ms, beats 100%
// Memory3: 9.29MB, beats 95.65%