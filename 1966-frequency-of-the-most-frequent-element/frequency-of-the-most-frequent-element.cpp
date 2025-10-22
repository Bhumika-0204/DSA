#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long total = 0;  // to avoid overflow
        int left = 0, ans = 1;

        for (int right = 0; right < nums.size(); right++) {
            total += nums[right];

            // Check cost to make all elements in window equal to nums[right]
            while ((long long)nums[right] * (right - left + 1) - total > k) {
                total -= nums[left];
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
