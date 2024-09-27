#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0) return -1;
        
        int cols = grid[0].size();
        int fresh_cnt = 0;
        queue<pair<int, int>> rotten;
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 2) {
                    rotten.push({r, c});
                } else if (grid[r][c] == 1) {
                    fresh_cnt++;
                }
            }
        }
        
        int minutes_passed = 0;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!rotten.empty() && fresh_cnt > 0) {
            minutes_passed++;
            int rotten_count = rotten.size();
            
            for (int i = 0; i < rotten_count; ++i) {
                auto [x, y] = rotten.front();
                rotten.pop();
                
                for (const auto& dir : directions) {
                    int xx = x + dir.first;
                    int yy = y + dir.second;
                    
                    if (xx < 0 || xx >= rows || yy < 0 || yy >= cols) continue;
                    if (grid[xx][yy] == 0 || grid[xx][yy] == 2) continue;
                    
                    grid[xx][yy] = 2;
                    fresh_cnt--;
                    rotten.push({xx, yy});
                }
            }
        }
        
        return fresh_cnt == 0 ? minutes_passed : -1;
    }
};

// Time Complexity:
// Space Complexity:

// Runtime1: 3ms, beats 84.60%
// Memory1: 16.13MB beats 91.22%

// Runtime2: 5ms, beats 57.32%
// Memory2: 16.24MB, beats 77.59%

// Runtime3: 3ms, beats 84.60%
// Memory3: 16.37MB, beats 58.72%