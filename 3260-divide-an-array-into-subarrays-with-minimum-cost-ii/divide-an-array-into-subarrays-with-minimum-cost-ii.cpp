class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();

        // We need k-1 starting points besides index 0
        multiset<int> small, large;
        long long sumSmall = 0;

        // Initial window: indices [1 .. dist+1]
        for (int i = 1; i <= dist + 1; i++) {
            small.insert(nums[i]);
            sumSmall += nums[i];
        }

        // Keep only k-1 smallest in 'small'
        while ((int)small.size() > k - 1) {
            auto it = prev(small.end());
            sumSmall -= *it;
            large.insert(*it);
            small.erase(it);
        }

        long long ans = nums[0] + sumSmall;

        // Slide the window
        for (int r = dist + 2; r < n; r++) {

            // Insert new element
            if (!small.empty() && nums[r] < *prev(small.end())) {
                small.insert(nums[r]);
                sumSmall += nums[r];
            } else {
                large.insert(nums[r]);
            }

            // Remove outgoing element (STRICT window)
            int out = nums[r - (dist + 1)];
            if (small.find(out) != small.end()) {
                small.erase(small.find(out));
                sumSmall -= out;
            } else {
                large.erase(large.find(out));
            }

            // Rebalance
            while ((int)small.size() < k - 1) {
                auto it = large.begin();
                sumSmall += *it;
                small.insert(*it);
                large.erase(it);
            }

            while ((int)small.size() > k - 1) {
                auto it = prev(small.end());
                sumSmall -= *it;
                large.insert(*it);
                small.erase(it);
            }

            ans = min(ans, nums[0] + sumSmall);
        }

        return ans;
    }
};
