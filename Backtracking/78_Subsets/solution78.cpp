#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        
        dfs(0, nums, subset, res);
        
        return res;
    }
    
private:
    void dfs(int i, vector<int>& nums, vector<int>& subset, vector<vector<int>>& res) {
        if (i >= nums.size()) {
            res.push_back(subset);
            return;
        }
        
        subset.push_back(nums[i]);
        dfs(i + 1, nums, subset, res);
        
        subset.pop_back();
        dfs(i + 1, nums, subset, res);
    }
};

// Runtime1: 0ms, beats 100%
// Memory1: 8.46MB, beats 91.20%

// Runtime2: 0ms, beats 100%
// Memory2: 8.43MB, beats 91.20%

// Runtime3: 0ms, beats 100%
// Memory3: 8.52MB, beats 76.45%