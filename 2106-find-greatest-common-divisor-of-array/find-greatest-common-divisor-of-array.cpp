class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = nums[0], mx = nums[0];
        for (int x : nums) {
            mn = min(mn, x);
            mx = max(mx, x);
        }
        return gcd(mx, mn);
    }
};
