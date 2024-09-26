#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        
        for (int i = 0; i < intervals.size(); ++i) {
            if (newInterval[1] < intervals[i][0]) {
                res.push_back(newInterval);
                res.insert(res.end(), intervals.begin() + i, intervals.end());
                return res;
            }
            else if (newInterval[0] > intervals[i][1]) {
                res.push_back(intervals[i]);
            }
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        
        res.push_back(newInterval);
        return res;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)

// Runtime1: 10ms, beats 67.93%
// Memory1: 20.80MB, beats 37.63%

// Runtime2:
// Memory2:

// Runtime3:
// Memory3: