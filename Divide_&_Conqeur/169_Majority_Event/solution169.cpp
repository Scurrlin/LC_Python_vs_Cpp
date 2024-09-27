#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, count = 0;

        for (int n : nums) {
            if (count == 0) {
                res = n;
            }
            count += (n == res) ? 1 : -1;
        }
        
        return res;
    }
};

// Runtime1: 15ms, beats 77.13%
// Memory1: 26.92MB, beats 79.70%

// Runtime2: 13ms, beats 83.67%
// Memory2: 27.04MB, beats 49.73%

// Runtime3: 15ms, beats 77.13%
// Memory3: 26.92MB, beats 79.70%