#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // Create a vector initialized with 0 of size n + 1
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        // Populate the dp array
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
};
