#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start_color = image[sr][sc];
        
        if (start_color == color) return image;
        
        flood_fill(image, sr, sc, start_color, color);
        
        return image;
    }
    
private:
    void flood_fill(vector<vector<int>>& image, int x, int y, int start_color, int color) {
        if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size()) return;
        
        if (image[x][y] != start_color) return;
        
        image[x][y] = color;
        
        flood_fill(image, x - 1, y, start_color, color);
        flood_fill(image, x + 1, y, start_color, color);
        flood_fill(image, x, y + 1, start_color, color);
        flood_fill(image, x, y - 1, start_color, color);
    }
};

// Time Complexity:
// Space Complexity:

// Runtime1: 4ms, beats 84.72%
// Memory1: 16.85MB, beats 86.60%

// Runtime2: 0ms, beats 100%
// Memory2: 16.72MB, beats 94.63%

// Runtime3: 0ms, beats 100%
// Memory3: 16.78MB, beats 94.63%