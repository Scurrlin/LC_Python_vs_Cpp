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

// Runtime1: 8ms, beats 80.37%
// Memory1: 20.71MB, beats 74.69%

// Runtime2: 7ms, beats 91.68%
// Memory2: 20.54MB, beats 98.70%

// Runtime3: 7ms, beats 91.68%
// Memory3: 20.80MB, beats 38.21%