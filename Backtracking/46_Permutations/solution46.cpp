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
