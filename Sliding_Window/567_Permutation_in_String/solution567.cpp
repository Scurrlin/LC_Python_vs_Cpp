#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        vector<int> s1Count(26, 0), s2Count(26, 0);
        
        for (int i = 0; i < s1.length(); ++i) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; ++i) {
            matches += (s1Count[i] == s2Count[i]) ? 1 : 0;
        }

        int l = 0;
        for (int r = s1.length(); r < s2.length(); ++r) {
            if (matches == 26) {
                return true;
            }

            int index = s2[r] - 'a';
            s2Count[index]++;
            if (s1Count[index] == s2Count[index]) {
                matches++;
            } else if (s1Count[index] + 1 == s2Count[index]) {
                matches--;
            }

            index = s2[l] - 'a';
            s2Count[index]--;
            if (s1Count[index] == s2Count[index]) {
                matches++;
            } else if (s1Count[index] - 1 == s2Count[index]) {
                matches--;
            }
            l++;
        }

        return matches == 26;
    }
};

// Time Complexity:
// Space Complexity:

// Runtime1: 4ms, beats 81.13%
// Memory1: 8.77MB, beats 80.92%

// Runtime2: 8ms, beats 56.96%
// Memory2: 8.68MB, beats 93.02%

// Runtime3: 4ms, beats 81.13%
// Memory3: 8.69MB, beats 93.02%