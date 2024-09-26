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
