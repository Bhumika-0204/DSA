class Solution {
public:
    int m,n;
    vector<vector<vector<int>>> dp;
    int f(int i,int j,int k,vector<vector<int>>&coins){
        if(i>=m || j>=n) return INT_MIN;

        int x=coins[i][j];

        if(i==m-1 && j==n-1){
            if(k>0) return max(0,x);
            return x;

        }
        if(dp[i][j][k]!=INT_MIN) return dp[i][j][k];
        int down = f(i + 1, j, k, coins);
        int right =f(i, j + 1, k, coins);

        int res = max(down, right) + x;
        if (k > 0 && x < 0) {
            int downN = f(i + 1, j, k - 1, coins);
            int rightN = f(i, j + 1, k - 1, coins);
            res = max(res, max(downN, rightN));
        }

        return dp[i][j][k] = res;

    }
    int maximumAmount(vector<vector<int>>& coins) {
        m=coins.size();
        n=coins[0].size();
        dp.assign(m,vector<vector<int>>(n,vector<int>(3,INT_MIN)));
        return f(0,0,2,coins);
    }
};