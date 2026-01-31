class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int r = -1, c = -1;

        // find the rook
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    r = i;
                    c = j;
                    break;
                }
            }
            if (r != -1) break;
        }

        int captures = 0;

        // up
        for (int i = r - 1; i >= 0; i--) {
            if (board[i][c] == 'B') break;
            if (board[i][c] == 'p') { captures++; break; }
        }

        // down
        for (int i = r + 1; i < 8; i++) {
            if (board[i][c] == 'B') break;
            if (board[i][c] == 'p') { captures++; break; }
        }

        // left
        for (int j = c - 1; j >= 0; j--) {
            if (board[r][j] == 'B') break;
            if (board[r][j] == 'p') { captures++; break; }
        }

        // right
        for (int j = c + 1; j < 8; j++) {
            if (board[r][j] == 'B') break;
            if (board[r][j] == 'p') { captures++; break; }
        }

        return captures;
    }
};
