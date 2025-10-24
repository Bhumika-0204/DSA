#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isBalanced(int x) {
        vector<int> cnt(10, 0);
        int y = x;
        while (y > 0) {
            int d = y % 10;
            if (d == 0) return false;
            cnt[d]++;
            y /= 10;
        }
        for (int d = 1; d <= 9; ++d) {
            if (cnt[d] > 0 && cnt[d] != d) {
                return false;
            }
        }
        return true;
    }

public:
    int nextBeautifulNumber(int n) {
        int candidate = n + 1;
        while (true) {
            if (isBalanced(candidate)) {
                return candidate;
            }
            ++candidate;
        }
        // unreachable given constraints
    }
};
