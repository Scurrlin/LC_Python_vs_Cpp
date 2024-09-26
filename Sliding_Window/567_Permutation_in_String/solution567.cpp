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
        
        // Populate character counts for s1 and the initial window of s2
        for (int i = 0; i < s1.length(); ++i) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        // Count the number of matches between s1Count and s2Count
        int matches = 0;
        for (int i = 0; i < 26; ++i) {
            matches += (s1Count[i] == s2Count[i]) ? 1 : 0;
        }

        // Use a sliding window approach to check the rest of s2
        int l = 0;
        for (int r = s1.length(); r < s2.length(); ++r) {
            if (matches == 26) {
                return true;
            }

            // Update the right pointer
            int index = s2[r] - 'a';
            s2Count[index]++;
            if (s1Count[index] == s2Count[index]) {
                matches++;
            } else if (s1Count[index] + 1 == s2Count[index]) {
                matches--;
            }

            // Update the left pointer
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
