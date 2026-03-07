class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string temp = s + s;

        string alt1 = "", alt2 = "";

        for (int i = 0; i < 2 * n; i++) {
            if (i % 2 == 0) {
                alt1 += '0';
                alt2 += '1';
            } else {
                alt1 += '1';
                alt2 += '0';
            }
        }

        int res = n;
        int diff1 = 0, diff2 = 0;
        int left = 0;

        for (int right = 0; right < 2 * n; right++) {

            if (temp[right] != alt1[right])
                diff1++;

            if (temp[right] != alt2[right])
                diff2++;

            if (right - left + 1 > n) {

                if (temp[left] != alt1[left])
                    diff1--;

                if (temp[left] != alt2[left])
                    diff2--;

                left++;
            }

            if (right - left + 1 == n) {
                res = min(res, min(diff1, diff2));
            }
        }

        return res;
    }
};