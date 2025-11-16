class Solution {
public:
    long long numSub(string s) {
        long long count = 0, ans = 0, MOD = 1e9 + 7;

        for (char c : s) {
            if (c == '1') {
                count++;
            } else {
                ans = (ans + (count * (count + 1) / 2)) % MOD;
                count = 0;
            }
        }

        // last block
        ans = (ans + (count * (count + 1) / 2)) % MOD;

        return ans;
    }
};
