#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }

        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;
        int end = points[0][1];

        for (const auto& point : points) {
            if (point[0] > end) {
                arrows++;
                end = point[1];
            }
        }

        return arrows;
    }
};

// Runtime1: 247ms, beats 74.24%
// Memory1: 93.52MB, beats 73.39%

// Runtime2: 253ms, beats 59.85%
// Memory2: 93.40MB, beats 96.81%

// Runtime3: 258ms, beats 48.52%
// Memory3: 93.31MB, beats 96.81%

// Runtime reduced by a factor of 10 to not skew data visualization