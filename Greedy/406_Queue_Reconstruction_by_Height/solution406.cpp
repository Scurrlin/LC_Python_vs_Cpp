#include <vector>
#include <algorithm> // For sort and insert functions

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Sort people by descending height and ascending order of k-values
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        
        vector<vector<int>> queue;
        
        // Insert each person at the position specified by their k-value
        for (const vector<int>& person : people) {
            queue.insert(queue.begin() + person[1], person);
        }
        
        return queue;
    }
};

// Time Complexity:
// Space Complexity:

// Runtime1: 28ms, beats 61.59%
// Memory1: 15.64MB, beats 53.12%