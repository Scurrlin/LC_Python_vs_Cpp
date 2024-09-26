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

// Time Complexity:
// Space Complexity:

// Runtime1:
// Memory1:

// Runtime2:
// Memory2:

// Runtime3:
// Memory3: