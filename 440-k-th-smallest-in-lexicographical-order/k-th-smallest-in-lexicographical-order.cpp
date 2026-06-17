class Solution {
public:
    long long f(long long n, long long curr, long long next) {
        long long steps=0;

        while (curr <= n) {
            steps += min(n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }

        return steps;
    }

    int findKthNumber(int n, int k) {
        long long curr = 1;
        k--;  

        while (k > 0) {
            long long y = f(n, curr, curr + 1);

            if (y <= k) {
                curr++;
                k -= y;
            } else {
                curr *= 10;
                k--;
            }
        }

        return curr;
    }
};