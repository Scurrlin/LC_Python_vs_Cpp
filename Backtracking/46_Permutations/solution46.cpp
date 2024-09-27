#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        
        if (nums.size() == 1) {
            return {nums};
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[0];
            nums.erase(nums.begin());
            
            vector<vector<int>> perms = permute(nums);
            
            for (auto& perm : perms) {
                perm.push_back(n);
            }
            
            res.insert(res.end(), perms.begin(), perms.end());
            
            nums.push_back(n);
        }
        
        return res;
    }
};

// Runtime1: 3ms, beats 52.66%
// Memory1: 11.91MB, beats 6.79%

// Runtime2: 3ms, beats 52.66%
// Memory2: 12.12MB, beats 6.40%

// Runtime3: 0ms, beats 100%
// Memory3: 12.11MB, beats 6.40%