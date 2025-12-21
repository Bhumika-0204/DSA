class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size();
        int m = A[0].size();
        vector<bool> sorted(n - 1, false);
        int deletions = 0;

        for (int c = 0; c < m; c++) {
            bool bad = false;

            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && A[i][c] > A[i + 1][c]) {
                    bad = true;
                    break;
                }
            }

            if (bad) {
                deletions++;
            } else {
                for (int i = 0; i < n - 1; i++) {
                    if (!sorted[i] && A[i][c] < A[i + 1][c]) {
                        sorted[i] = true;
                    }
                }
            }
        }
        return deletions;
    }
};
