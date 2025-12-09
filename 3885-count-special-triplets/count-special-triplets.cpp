class Solution {
public:
    static const long long MOD = 1e9 + 7;

    int specialTriplets(vector<int>& nums) {
        unordered_map<long long, long long> leftCount, rightCount;
        for (long long x : nums) rightCount[x]++;

        long long ans = 0;
        for (int j = 0; j < (int)nums.size(); ++j) {
            long long val = nums[j];
            long long need = val * 2;
            rightCount[val]--;
            long long leftWays = leftCount[need];
            long long rightWays = rightCount[need];
            ans = (ans + (leftWays * rightWays) % MOD) % MOD;
            leftCount[val]++;
        }
        return (int)(ans % MOD);
    }
};
