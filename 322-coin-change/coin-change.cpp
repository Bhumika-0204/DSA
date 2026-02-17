class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& coins, int amount) {

        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;

        if (dp[amount] != -1) return dp[amount];

        int res = INT_MAX;

        for (int coin : coins) {
            int sub = solve(coins, amount - coin);
            if (sub != INT_MAX)
                res = min(res, 1 + sub);
        }

        return dp[amount] = res;
    }

    int coinChange(vector<int>& coins, int amount) {

        dp.assign(amount + 1, -1);

        int ans = solve(coins, amount);

        return ans == INT_MAX ? -1 : ans;
    }
};
