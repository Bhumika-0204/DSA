class Solution {
public:
    int minCost(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        deque<pair<int,int>> dq;

        dq.push_front({0,0});
        dist[0][0] = 0;

        while(!dq.empty()) {

            auto [x,y] = dq.front();
            dq.pop_front();

            for(int i=0;i<4;i++) {

                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx<0 || ny<0 || nx>=n || ny>=m)
                    continue;

                int edgewt = (grid[x][y] == i+1) ? 0 : 1;

                if(dist[nx][ny] > dist[x][y] + edgewt) {

                    dist[nx][ny] = dist[x][y] + edgewt;

                    if(edgewt == 0)
                        dq.push_front({nx,ny});
                    else
                        dq.push_back({nx,ny});
                }
            }
        }

        return dist[n-1][m-1];
    }
};