#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        
        for (int i = 0; i < intervals.size(); ++i) {
            // Case 1: If the new interval comes before the current interval
            if (newInterval[1] < intervals[i][0]) {
                res.push_back(newInterval);
                // Append the remaining intervals and return
                res.insert(res.end(), intervals.begin() + i, intervals.end());
                return res;
            }
            // Case 2: If the new interval comes after the current interval
            else if (newInterval[0] > intervals[i][1]) {
                res.push_back(intervals[i]);
            }
            // Case 3: If the new interval overlaps with the current interval
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        
        // Append the merged interval at the end
        res.push_back(newInterval);
        return res;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)

// Runtime1: 10ms, beats 67.93%
// Memory1: 20.80MB, beats 37.63%