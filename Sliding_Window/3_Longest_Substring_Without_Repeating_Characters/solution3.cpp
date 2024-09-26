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
            // If the character at position r is already in the set, move left pointer
            while (charSet.find(s[r]) != charSet.end()) {
                charSet.erase(s[l]);
                l++;
            }
            // Insert the current character into the set
            charSet.insert(s[r]);
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};
