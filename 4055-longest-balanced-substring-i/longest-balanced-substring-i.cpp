class Solution {
public:
    int longestBalanced(string s) {

        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            int freq[26] = {0};
            int distinct = 0;
            int maxFreq = 0;

            for (int j = i; j < n; j++) {

                int idx = s[j] - 'a';

                if (freq[idx] == 0) {
                    distinct++;
                }

                freq[idx]++;
                maxFreq = max(maxFreq, freq[idx]);

                if (isBalanced(freq, maxFreq)) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }

private:
    bool isBalanced(int freq[], int maxFreq) {

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0 && freq[i] != maxFreq) {
                return false;
            }
        }

        return true;
    }
};