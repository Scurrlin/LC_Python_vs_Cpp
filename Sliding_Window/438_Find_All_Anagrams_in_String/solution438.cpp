#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int startIndex = 0;
        unordered_map<char, int> pMap, sMap;
        vector<int> res;

        // Populate pMap with character counts from string p
        for (char c : p) {
            pMap[c]++;
        }

        // Sliding window approach
        for (int i = 0; i < s.length(); ++i) {
            sMap[s[i]]++; // Add current character to the sMap

            // Check if the window size matches the size of p
            if (i >= p.length() - 1) {
                // If the frequency maps match, add the starting index to the result
                if (sMap == pMap) {
                    res.push_back(startIndex);
                }

                // Remove the leftmost character from the window
                if (sMap[s[startIndex]] > 1) {
                    sMap[s[startIndex]]--;
                } else {
                    sMap.erase(s[startIndex]);
                }
                
                startIndex++; // Slide the window to the right
            }
        }

        return res;
    }
};
