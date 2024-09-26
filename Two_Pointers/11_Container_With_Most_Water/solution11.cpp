#include <vector>
#include <algorithm> // For the max and min functions

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            // Calculate the area with the current left and right pointers
            int area = min(height[left], height[right]) * (right - left);
            max_area = max(max_area, area);

            // Move the pointer corresponding to the smaller height
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_area;
    }
};
