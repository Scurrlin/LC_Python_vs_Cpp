#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
};

// Runtime1: 0ms, beats 100%
// Memory1: 7.60MB, beats 49.98%

// Runtime2: 0ms, beats 100%
// Memory2: 7.54MB, beats 49.98%

// Runtime3: 0ms, beats 100%
// Memory3: 7.64MB, beats 38.17%