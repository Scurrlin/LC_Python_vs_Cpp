#include <vector>
#include <algorithm> // For the max function

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // Initialize LIS array with 1s, similar to the Python version
        vector<int> LIS(nums.size(), 1);

        // Iterate from the end of the array to the beginning
        for (int i = nums.size() - 1; i >= 0; --i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] < nums[j]) {
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
                }
            }
        }
        
        return *max_element(LIS.begin(), LIS.end()); // Return the maximum value in the LIS array
    }
};
