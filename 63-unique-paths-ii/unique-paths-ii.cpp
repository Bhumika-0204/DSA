class Solution {
public:
    int m,n;
    vector<vector<int>> grid,dp;
        int f(int i,int j){

            //(for index out of bound)
            if(i>=n ||j>=m) return 0;



            //for(obstacle)
            if(grid[i][j]==1) return 0;

            //(for destination)
            if(i==n-1 &&j==m-1) return 1;

            if(dp[i][j]!=-1) return dp[i][j];
            return dp[i][j]=f(i,j+1) +f(i+1,j);
        }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        grid=obstacleGrid;
        n=grid.size();
        m=grid[0].size();
        if(grid[n-1][m-1]==1) return 0;
        dp.resize(n, vector<int>(m, -1));
        return f(0,0);

    }
};