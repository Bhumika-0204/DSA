class Solution {
    int m, n;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        vis[x][y] = 1;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                grid[nx][ny] == 1 && !vis[nx][ny]) {
                dfs(nx, ny, grid, vis);
            }
        }
    }

    int countislands(vector<vector<int>>& grid) {
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    islands++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return islands;
    }

public:
    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if (countislands(grid) != 1)
            return 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (countislands(grid) != 1)
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};
