#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int l = 0, res = 0;

        for (int r = 0; r < s.length(); ++r) {
            while (charSet.find(s[r]) != charSet.end()) {
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]);
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};

// Runtime1: 24ms, beats 27.86%
// Memory1: 14.38MB, beats 38.16%

// Runtime2: 20ms, beats 38.78%
// Memory2: 14.47MB, beats 36.94%

// Runtime3: 24ms, beats 27.86%
// Memory3: 14.57MB, beats 33.48%