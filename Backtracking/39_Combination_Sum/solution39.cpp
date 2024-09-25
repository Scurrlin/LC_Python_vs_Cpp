#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentCombination;
        
        // Start backtracking
        backtrack(candidates, target, 0, currentCombination, result);
        
        return result;
    }
    
private:
    void backtrack(vector<int>& candidates, int target, int startIndex, vector<int>& currentCombination, vector<vector<int>>& result) {
        // Base case: when target is reached
        if (target == 0) {
            result.push_back(currentCombination);
            return;
        }
        
        // Try each candidate starting from 'startIndex'
        for (int i = startIndex; i < candidates.size(); ++i) {
            // If the current candidate exceeds the target, skip further exploration
            if (candidates[i] > target) continue;
            
            // Choose the candidate
            currentCombination.push_back(candidates[i]);
            
            // Recursively explore with the updated target and current combination
            // Note that 'i' is passed instead of 'i + 1' since the same candidate can be used again
            backtrack(candidates, target - candidates[i], i, currentCombination, result);
            
            // Backtrack: remove the last added element
            currentCombination.pop_back();
        }
    }
};
