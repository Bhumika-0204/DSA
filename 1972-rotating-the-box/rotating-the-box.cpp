class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        vector<vector<char>> rotated(n, vector<char>(m));

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                rotated[col][m - 1 - row] = boxGrid[row][col];
            }
        }

        for (int col = 0; col < m; col++) {
            int emptyRow = n - 1;

            for (int row = n - 1; row >= 0; row--) {
                if (rotated[row][col] == '*') {
                    emptyRow = row - 1;
                } else if (rotated[row][col] == '#') {
                    swap(rotated[row][col], rotated[emptyRow][col]);
                    emptyRow--;
                }
            }
        }

        return rotated;
    }
};