#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        long long S = 0;
        for (int x : nums) {
            S += x;
        }
        long long L = 0;
        long long ans = 0;
        for (int x : nums) {
            if (x != 0) {
                L += x;
            } else {
                long long twoL = L * 2;
                if (twoL == S) {
                    ans += 2;
                } else if (llabs(twoL - S) == 1) {
                    ans += 1;
                }
            }
        }
        return (int)ans;
    }
};
