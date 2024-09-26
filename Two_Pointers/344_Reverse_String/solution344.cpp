#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            // Swap the elements at positions l and r
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
};
