class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;
    int n;

    void solve(int row, int cols, int d1, int d2) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        int available = ((1 << n) - 1) & ~(cols | d1 | d2);

        while (available) {
            int pos = available & -available; 
            available -= pos;

            int col = __builtin_ctz(pos); 

            board[row][col] = 'Q';

            solve(row + 1,
                  cols | pos,
                  (d1 | pos) << 1,
                  (d2 | pos) >> 1);

            board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        board = vector<string>(n, string(n, '.'));
        solve(0, 0, 0, 0);
        return ans;
    }
};