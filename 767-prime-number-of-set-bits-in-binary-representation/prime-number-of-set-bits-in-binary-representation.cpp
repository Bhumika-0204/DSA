class Solution {
public:
    int countPrimeSetBits(int left, int right) {

        unordered_set<int> prime = {2,3,5,7,11,13,17,19};

        int ans = 0;

        for (int num = left; num <= right; num++) {

            int bits = __builtin_popcount(num);

            if (prime.count(bits))
                ans++;
        }

        return ans;
    }
};