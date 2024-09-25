#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        
        // Base case
        if (nums.size() == 1) {
            return {nums}; // Return a 2D vector with a single permutation
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[0];
            nums.erase(nums.begin()); // Remove the first element
            
            vector<vector<int>> perms = permute(nums); // Recursively get permutations of the remaining elements
            
            // Add the removed element `n` to each permutation
            for (auto& perm : perms) {
                perm.push_back(n);
            }
            
            // Add all permutations to the result
            res.insert(res.end(), perms.begin(), perms.end());
            
            nums.push_back(n); // Restore the removed element to the end of the list
        }
        
        return res;
    }
};
