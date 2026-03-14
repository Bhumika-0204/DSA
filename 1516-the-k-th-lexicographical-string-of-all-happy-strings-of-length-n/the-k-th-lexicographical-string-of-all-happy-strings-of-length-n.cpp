class Solution {
public:
    vector<string> ans;

    void generate(int n, string curr) {
        if(curr.size() == n) {
            ans.push_back(curr);
            return;
        }

        for(char c : {'a','b','c'}) {
            if(curr.empty() || curr.back() != c) {
                generate(n, curr + c);
            }
        }
    }

    string getHappyString(int n, int k) {
        generate(n, "");

        if(ans.size() < k) return "";
        return ans[k-1];
    }
};