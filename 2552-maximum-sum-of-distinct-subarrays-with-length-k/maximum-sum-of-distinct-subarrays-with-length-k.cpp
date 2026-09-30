class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        long long sum = 0;
        long long ans = 0;

        int lo = 0;

        for (int hi = 0; hi < nums.size(); hi++) {

            sum += nums[hi];
            freq[nums[hi]]++;

            if (hi - lo + 1 > k) {

                sum -= nums[lo];
                freq[nums[lo]]--;

                if (freq[nums[lo]] == 0)
                    freq.erase(nums[lo]);

                lo++;
            }

            if (hi - lo + 1 == k && freq.size() == k) {
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};