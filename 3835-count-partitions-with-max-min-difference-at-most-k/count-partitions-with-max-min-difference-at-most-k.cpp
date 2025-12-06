class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<long long> dp(n + 1, 0), pref(n + 1, 0);
        dp[0] = 1;
        pref[0] = 1;

        deque<int> minq, maxq;
        int left = 0;

        for (int i = 0; i < n; i++) {

            while (!maxq.empty() && nums[i] > maxq.back()) maxq.pop_back();
            maxq.push_back(nums[i]);

            while (!minq.empty() && nums[i] < minq.back()) minq.pop_back();
            minq.push_back(nums[i]);

            while (!maxq.empty() && !minq.empty() && (maxq.front() - minq.front() > k)) {

                if (nums[left] == maxq.front()) maxq.pop_front();
                if (nums[left] == minq.front()) minq.pop_front();
                left++;
            }

            long long total = pref[i];
            long long remove = (left > 0 ? pref[left - 1] : 0);

            dp[i + 1] = (total - remove + MOD) % MOD;
            pref[i + 1] = (pref[i] + dp[i + 1]) % MOD;
        }

        return dp[n];
    }
};
