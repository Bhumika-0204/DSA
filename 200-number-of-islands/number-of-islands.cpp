class Solution {
public:
    int n, m;   // ✅ declared at class level

    void dfs(int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || j < 0 || i >= n || j >= m) return;
        if (grid[i][j] == '0') return;

        grid[i][j] = '0';

        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int islands = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};
