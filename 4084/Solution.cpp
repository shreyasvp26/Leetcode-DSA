// 4084. Last Visited Cell in a Directional Grid - https://leetcode.com/problems/last-visited-cell-in-a-directional-grid/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int r = 0, c = 0;
        vis[0][0] = 1;
        while (true) {
            int nr = r, nc = c;
            if (grid[r][c] == 'L') {
                nc--;
            }
            else if (grid[r][c] == 'R') {
                nc++;
            }
            else if (grid[r][c] == 'U') {
                nr--;
            }
            else if (grid[r][c] == 'D') {
                nr++;
            }
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                return {r, c};
            }
            if (vis[nr][nc]) {
                return {r, c};
            }
            r = nr;
            c = nc;
            vis[r][c] = 1;
        }
        return {r, c};
    }
};

// Time Complexity: O(n * m) - In the worst case, we may visit all cells in the grid.
// Space Complexity: O(n * m) - We use a 2D vector to keep track of visited cells, which requires additional space proportional to the size of the grid.