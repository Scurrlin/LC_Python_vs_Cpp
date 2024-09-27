#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int num_islands = 0;
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    num_islands++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return num_islands;
    }
    
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
            return;
        }
        
        grid[i][j] = '0';
        
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};

// Time Complexity:
// Space Complexity:

// Runtime1: 19ms, beats 97.62%
// Memory1: 15.83MB, beats 98.93%

// Runtime2: 23ms, beats 88.67%
// Memory2: 16.06MB, beats 85.35%

// Runtime3: 22ms, beats 92.46%
// Memory3: 15.88MB, beats 98.93%