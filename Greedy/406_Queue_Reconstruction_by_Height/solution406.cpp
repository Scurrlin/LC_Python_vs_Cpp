#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        
        vector<vector<int>> queue;
        
        for (const vector<int>& person : people) {
            queue.insert(queue.begin() + person[1], person);
        }
        
        return queue;
    }
};

// Runtime1: 28ms, beats 61.59%
// Memory1: 15.64MB, beats 53.12%

// Runtime2: 25ms, beats 76.96%
// Memory2: 15.50MB, beats 60.75%

// Runtime3: 27ms, beats 68.75%
// Memory3: 15.72MB, beats 44.20%