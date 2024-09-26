#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentCombination;
        
        backtrack(candidates, target, 0, currentCombination, result);
        
        return result;
    }
    
private:
    void backtrack(vector<int>& candidates, int target, int startIndex, vector<int>& currentCombination, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(currentCombination);
            return;
        }
        
        for (int i = startIndex; i < candidates.size(); ++i) {
            if (candidates[i] > target) continue;
            currentCombination.push_back(candidates[i]);
            
            backtrack(candidates, target - candidates[i], i, currentCombination, result);
            
            currentCombination.pop_back();
        }
    }
};
