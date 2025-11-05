class Solution {
public:
    bool searchInRow(vector<vector<int>>& mat, int target, int row) {
        int n = mat[0].size();
        int st = 0, end = n - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (mat[row][mid] == target) return true;
            else if (mat[row][mid] < target) st = mid + 1;
            else end = mid - 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;

        int start = 0, end = m - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (target < matrix[mid][0]) {
                end = mid - 1;
            } else if (target > matrix[mid][n - 1]) {
                start = mid + 1;
            } else {
                // target must be in this row range
                return searchInRow(matrix, target, mid);
            }
        }
        return false;
    }
};
