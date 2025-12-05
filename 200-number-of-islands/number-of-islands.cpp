class Solution {
public:
    void dfs(int r, int c, vector<vector<char>> &grid, int n, int m) {
        if(r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == '0')
            return;

        grid[r][c] = '0';  // mark visited
        
        dfs(r+1, c, grid, n, m);
        dfs(r-1, c, grid, n, m);
        dfs(r, c+1, grid, n, m);
        dfs(r, c-1, grid, n, m);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid, n, m);
                }
            }
        }
        return count;
    }
};