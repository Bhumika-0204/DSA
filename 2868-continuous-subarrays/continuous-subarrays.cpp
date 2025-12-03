class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        multiset<int> ms;
        long long ans = 0;
        int l = 0;

        for (int r = 0; r < nums.size(); r++) {
            ms.insert(nums[r]);

            while (*ms.rbegin() - *ms.begin() > 2) {
                ms.erase(ms.find(nums[l]));
                l++;
            }

            ans += (r - l + 1);
        }

        return ans;
    }
};
