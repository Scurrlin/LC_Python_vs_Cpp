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

        for (char c : p) {
            pMap[c]++;
        }

        for (int i = 0; i < s.length(); ++i) {
            sMap[s[i]]++;

            if (i >= p.length() - 1) {
                if (sMap == pMap) {
                    res.push_back(startIndex);
                }

                if (sMap[s[startIndex]] > 1) {
                    sMap[s[startIndex]]--;
                } else {
                    sMap.erase(s[startIndex]);
                }
                
                startIndex++;
            }
        }

        return res;
    }
};

// Runtime1: 38ms, beats 18.97%
// Memory1: 15.41MB, beats 18.19%

// Runtime2: 36ms, beats 21.63%
// Memory2: 15.33MB, beats 20.49%

// Runtime3: 33ms, beats 25.95%
// Memory3: 15.13MB, beats 21.84%