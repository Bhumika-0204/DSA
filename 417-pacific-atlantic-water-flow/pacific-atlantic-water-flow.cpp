class Solution {
public:

    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    void bfs(queue<pair<int,int>>& q,
             vector<vector<int>>& vis,
             vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        while(!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0;i<4;i++) {

                int nr = r + dir[i][0];
                int nc = c + dir[i][1];

                if(nr>=0 && nc>=0 &&
                   nr<rows && nc<cols &&
                   !vis[nr][nc] &&
                   heights[nr][nc] >= heights[r][c]) {

                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> pac(rows, vector<int>(cols,0));
        vector<vector<int>> atl(rows, vector<int>(cols,0));

        queue<pair<int,int>> pacQ;
        queue<pair<int,int>> atlQ;

        
        for(int c=0;c<cols;c++) {
            pac[0][c] = 1;
            pacQ.push({0,c});
        }

        for(int r=0;r<rows;r++) {
            pac[r][0] = 1;
            pacQ.push({r,0});
        }

    
        for(int c=0;c<cols;c++) {
            atl[rows-1][c] = 1;
            atlQ.push({rows-1,c});
        }

        for(int r=0;r<rows;r++) {
            atl[r][cols-1] = 1;
            atlQ.push({r,cols-1});
        }

        bfs(pacQ, pac, heights);
        bfs(atlQ, atl, heights);

        vector<vector<int>> ans;

        for(int r=0;r<rows;r++) {
            for(int c=0;c<cols;c++) {

                if(pac[r][c] && atl[r][c]) {
                    ans.push_back({r,c});
                }
            }
        }

        return ans;
    }
};