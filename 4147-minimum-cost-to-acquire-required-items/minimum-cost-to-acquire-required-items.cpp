
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        long long common = min(need1, need2);
        long long ans = 0;

        // Satisfy common requirements
        ans += common * min(costBoth, cost1 + cost2);

        // Remaining type 1 requirements
        ans += max(0, need1 - need2) * 1LL * min(cost1, costBoth);

        // Remaining type 2 requirements
        ans += max(0, need2 - need1) * 1LL * min(cost2, costBoth);

        return ans;
    }
};
