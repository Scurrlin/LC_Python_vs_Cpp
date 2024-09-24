#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort the intervals based on the starting value
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        
        // Initialize the output with the first interval
        vector<vector<int>> output = { intervals[0] };
        
        // Iterate through each interval
        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            int& lastEnd = output.back()[1];
            
            if (start <= lastEnd) {
                // Merge intervals
                lastEnd = max(lastEnd, end);
            } else {
                // Add a new interval
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