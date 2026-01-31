class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban;
        for (string &b : banned) {
            ban.insert(b);
        }

        unordered_map<string, int> freq;
        string word = "";

        for (int i = 0; i <= paragraph.size(); i++) {
            if (i < paragraph.size() && isalpha(paragraph[i])) {
                word += tolower(paragraph[i]);
            } else {
                if (!word.empty() && ban.find(word) == ban.end()) {
                    freq[word]++;
                }
                word = "";
            }
        }

        string ans = "";
        int mx = 0;
        for (auto &p : freq) {
            if (p.second > mx) {
                mx = p.second;
                ans = p.first;
            }
        }
        return ans;
    }
};
