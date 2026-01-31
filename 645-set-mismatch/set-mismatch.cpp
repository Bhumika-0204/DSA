class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0, sqSum = 0;

        for (int x : nums) {
            sum += x;
            sqSum += 1LL * x * x;
        }

        long long expectedSum = 1LL * n * (n + 1) / 2;
        long long expectedSqSum = 1LL * n * (n + 1) * (2 * n + 1) / 6;

        long long diff = sum - expectedSum;              // duplicate - missing
        long long sqDiff = sqSum - expectedSqSum;        // dup^2 - miss^2

        long long sumDM = sqDiff / diff;                 // duplicate + missing

        int duplicate = (diff + sumDM) / 2;
        int missing = sumDM - duplicate;

        return {duplicate, missing};
    }
};
