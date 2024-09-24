#include <vector>
#include <algorithm> // For sort function

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // Sort the points based on their starting values
        sort(points.begin(), points.end());

        int res = points.size();
        vector<int> prev = points[0];
        
        for (int i = 1; i < points.size(); ++i) {
            vector<int>& curr = points[i];

            // Check if there is an overlap with the previous balloon
            if (curr[0] <= prev[1]) {
                res--; // One less arrow needed
                prev[1] = min(curr[1], prev[1]); // Update the end of the overlap
            } else {
                prev = curr; // Move to the next balloon
            }
        }
        
        return res;
    }
};
