class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0, high = 0, res = INT_MIN;
        int zeros = 0;

        for (high = 0; high < n; high++) {
            if (nums[high] == 0)
                zeros++;

            int len = high - low + 1;
            int diff = zeros;

            while (diff > k) {
                if (nums[low] == 0)
                    zeros--;

                low++;
                len = high - low + 1;
                diff = zeros;
            }

            len = high - low + 1;
            res = max(res, len);
        }

        return res;
    }
};