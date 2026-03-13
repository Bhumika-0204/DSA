#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxHeight(long long T, int t) {
        long double val = 1 + (8.0 * T) / t;
        long long x = (sqrt(val) - 1) / 2;
        return x;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 0;
        long long right = 1e18;
        long long ans = right;

        while(left <= right) {
            long long mid = left + (right - left) / 2;

            long long total = 0;

            for(int t : workerTimes) {
                total += maxHeight(mid, t);
                if(total >= mountainHeight) break;
            }

            if(total >= mountainHeight) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};