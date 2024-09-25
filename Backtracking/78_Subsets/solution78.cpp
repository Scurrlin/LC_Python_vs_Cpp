#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        
        // Start the depth-first search from index 0
        dfs(0, nums, subset, res);
        
        return res;
    }
    
private:
    // Depth-First Search function to generate subsets
    void dfs(int i, vector<int>& nums, vector<int>& subset, vector<vector<int>>& res) {
        if (i >= nums.size()) {
            res.push_back(subset); // Add the current subset to the result
            return;
        }
        
        // Decision to include nums[i]
        subset.push_back(nums[i]);
        dfs(i + 1, nums, subset, res);
        
        // Decision NOT to include nums[i]
        subset.pop_back();
        dfs(i + 1, nums, subset, res);
    }
};
