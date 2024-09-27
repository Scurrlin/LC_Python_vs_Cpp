#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int area = min(height[left], height[right]) * (right - left);
            max_area = max(max_area, area);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_area;
    }
};

// Runtime1: 57ms, beats 76.79%
// Memory1: 61.63MB, beats 74.81%

// Runtime2: 52ms, beats 90.80%
// Memory2: 61.69MB, beats 74.81%

// Runtime3: 55ms, beats 84.07%
// Memory3: 61.48MB, beats 98.64%