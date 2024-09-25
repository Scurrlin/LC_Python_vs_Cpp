#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start_color = image[sr][sc];
        
        // If the starting pixel already has the target color, return the image
        if (start_color == color) return image;
        
        // Start the flood fill
        flood_fill(image, sr, sc, start_color, color);
        
        return image;
    }
    
private:
    // Depth-First Search function for flood fill
    void flood_fill(vector<vector<int>>& image, int x, int y, int start_color, int color) {
        // Base case: check boundaries
        if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size()) return;
        
        // Check if the current cell is already filled with the target color or doesn't match the start color
        if (image[x][y] != start_color) return;
        
        // Fill the current cell with the target color
        image[x][y] = color;
        
        // Recursively call flood_fill in all four directions
        flood_fill(image, x - 1, y, start_color, color); // Up
        flood_fill(image, x + 1, y, start_color, color); // Down
        flood_fill(image, x, y + 1, start_color, color); // Right
        flood_fill(image, x, y - 1, start_color, color); // Left
    }
};
