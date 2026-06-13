class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;

        for (string &word : words) {
            long long total = 0;

            for (char ch : word) {
                total += weights[ch - 'a'];
            }

            int rem = total % 26;
            ans.push_back('z' - rem);
        }

        return ans;
    }
};