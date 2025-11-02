#include <vector>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n,
                       vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        // 0 = unoccupied & unguarded, 1 = guarded, 2 = guard/wall (occupied)
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (auto &g : guards) {
            grid[g[0]][g[1]] = 2;
        }
        for (auto &w : walls) {
            grid[w[0]][w[1]] = 2;
        }
        int dirs[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        for (auto &g : guards) {
            int r = g[0], c = g[1];
            for (int d = 0; d < 4; ++d) {
                int dr = dirs[d][0], dc = dirs[d][1];
                int rr = r + dr, cc = c + dc;
                while (rr >= 0 && rr < m && cc >= 0 && cc < n && grid[rr][cc] != 2) {
                    // If not an occupied cell, mark as guarded (1)
                    if (grid[rr][cc] == 0) {
                        grid[rr][cc] = 1;
                    }
                    rr += dr;
                    cc += dc;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0)
                    ++count;
        return count;
    }
};
