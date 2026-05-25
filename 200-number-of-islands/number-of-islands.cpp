class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        int cc = 0;

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {

                if(grid[r][c] == '0')
                    continue;

                cc++;                     //  new island mil gya
                grid[r][c] = '0';

                queue<pair<int,int>> q;
                q.push({r,c});

                while(!q.empty()) {

                    auto curr = q.front();
                    q.pop();

                    int currRow = curr.first;
                    int currCol = curr.second;

                    // up
                    if(currRow-1 >= 0 &&
                       grid[currRow-1][currCol]=='1') {

                        q.push({currRow-1,currCol});
                        grid[currRow-1][currCol]='0';
                    }

                    // down
                    if(currRow+1 < rows &&
                       grid[currRow+1][currCol]=='1') {

                        q.push({currRow+1,currCol});
                        grid[currRow+1][currCol]='0';
                    }

                    // left
                    if(currCol-1 >= 0 &&
                       grid[currRow][currCol-1]=='1') {

                        q.push({currRow,currCol-1});
                        grid[currRow][currCol-1]='0';
                    }

                    // right
                    if(currCol+1 < cols &&
                       grid[currRow][currCol+1]=='1') {

                        q.push({currRow,currCol+1});
                        grid[currRow][currCol+1]='0';
                    }
                }
            }
        }

        return cc;
    }
};