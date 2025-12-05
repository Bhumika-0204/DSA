class Solution {
public:
    int countPartitions(vector<int>& nums) {
        long long total = 0;
        for (int x : nums) total += x;

        int n = nums.size();
        if (total % 2 == 0)
            return n - 1;
        else
            return 0;
    }
};
