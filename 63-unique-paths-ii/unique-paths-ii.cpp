class Solution {
public:
    int helper(int r,int c,vector<vector<int>>&obstacleGrid,vector<vector<int>>&dp){
        if(r<0||c<0) return 0;
        if(obstacleGrid[r][c]==1) return 0;
        if(r==0&&c==0) return 1;

        if(dp[r][c]!=-1) return dp[r][c];
        int up=helper(r-1,c,obstacleGrid,dp);
        int down=helper(r,c-1,obstacleGrid,dp);
        return dp[r][c]=up+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,obstacleGrid,dp);
    }
};