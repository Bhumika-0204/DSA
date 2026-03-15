class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        long long prev = -1e18;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {

            long long L = nums[i] - k;
            long long R = nums[i] + k;

            long long candidate = max(prev + 1, L);

            if (candidate <= R) {
                count++;
                prev = candidate;
            }
        }

        return count;
    }
};