class Solution {
public:
    bool isMagic(vector<vector<int>>& g, int r, int c) {
        vector<int> freq(10, 0);

        // Check numbers 1 to 9 exactly once
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int x = g[i][j];
                if (x < 1 || x > 9 || freq[x]++) return false;
            }
        }

        int sum = g[r][c] + g[r][c+1] + g[r][c+2];

        for (int i = 0; i < 3; i++) {
            if (g[r+i][c] + g[r+i][c+1] + g[r+i][c+2] != sum) return false;
            if (g[r][c+i] + g[r+1][c+i] + g[r+2][c+i] != sum) return false;
        }

        if (g[r][c] + g[r+1][c+1] + g[r+2][c+2] != sum) return false;
        if (g[r][c+2] + g[r+1][c+1] + g[r+2][c] != sum) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        for (int i = 0; i + 2 < m; i++) {
            for (int j = 0; j + 2 < n; j++) {
                if (grid[i+1][j+1] == 5 && isMagic(grid, i, j))
                    ans++;
            }
        }
        return ans;
    }
};
