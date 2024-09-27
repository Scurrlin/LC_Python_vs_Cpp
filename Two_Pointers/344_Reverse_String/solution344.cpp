#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
};

// Time Complexity:
// Space Complexity:

// Runtime1: 20ms, beats 36.80%
// Memory1: 27.12MB, beats 86.58%

// Runtime2: 21ms, beats 25.95%
// Memory2: 27.23MB, beats 66.72%

// Runtime3: 19ms, beats 46.80%
// Memory3: 27.28MB, beats 66.72%