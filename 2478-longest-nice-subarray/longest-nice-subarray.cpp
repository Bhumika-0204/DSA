class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int low = 0, used = 0, res = 0;

        for (int high = 0; high < nums.size(); high++) {
            while ((used & nums[high]) != 0) {
                used ^= nums[low];
                low++;
            }

            used |= nums[high];
            res = max(res, high - low + 1);
        }

        return res;
    }
};