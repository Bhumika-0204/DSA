class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int area = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int h = grid[i][j];
                if (h > 0) {
                    // top + bottom
                    area += 2;

                    // four sides
                    area += max(h - (i > 0 ? grid[i-1][j] : 0), 0);
                    area += max(h - (i < n-1 ? grid[i+1][j] : 0), 0);
                    area += max(h - (j > 0 ? grid[i][j-1] : 0), 0);
                    area += max(h - (j < n-1 ? grid[i][j+1] : 0), 0);
                }
            }
        }
        return area;
    }
};
