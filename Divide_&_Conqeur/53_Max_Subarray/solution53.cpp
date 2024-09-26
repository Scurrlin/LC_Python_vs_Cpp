#include <vector>
#include <algorithm> // For the max function

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
