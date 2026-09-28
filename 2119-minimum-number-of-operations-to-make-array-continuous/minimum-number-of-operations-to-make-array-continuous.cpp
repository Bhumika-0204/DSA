class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        int low = 0, res = n;

        for (int high = 0; high < nums.size(); high++) {
            while (nums[high] - nums[low] >= n)
                low++;

            int len = high - low + 1;
            res = min(res, n - len);
        }

        return res;
    }
};