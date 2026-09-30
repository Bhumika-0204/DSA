class Solution {
public:
    long long countGood(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        long long pairs = 0;
        long long ans = 0;

        int lo = 0;

        for (int hi = 0; hi < nums.size(); hi++) {

            pairs += freq[nums[hi]];

            freq[nums[hi]]++;

            while (pairs >= k) {
                ans += nums.size() - hi;

                freq[nums[lo]]--;

                pairs -= freq[nums[lo]];

                lo++;
            }
        }

        return ans;
    }
};