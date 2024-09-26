#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        
        vector<vector<int>> output = { intervals[0] };
        
        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            int& lastEnd = output.back()[1];
            
            if (start <= lastEnd) {
                lastEnd = max(lastEnd, end);
            } else {
                output.push_back(interval);
            }
        }
        
        return output;
    }
};

// Time Complexity: 0(NlogN)
// Space Complexity: 0(N)

// Runtime1: 18ms, beats 88.37%
// Memory1: 22.90MB, beats 72.73%

// Runtime2:
// Memory2:

// Runtime3:
// Memory3: