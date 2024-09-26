#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); // Sort the array

        for (int i = 0; i < nums.size(); ++i) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];

                if (total > 0) {
                    k--; // Decrease the right pointer to reduce the sum
                } else if (total < 0) {
                    j++; // Increase the left pointer to increase the sum
                } else {
                    // Found a triplet that sums to zero
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    
                    // Skip duplicates for the second element
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                }
            }
        }
        
        return res;
    }
};
