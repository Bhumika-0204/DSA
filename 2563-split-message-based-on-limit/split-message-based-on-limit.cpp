class Solution {
public:
    int sz(int n) {
        return to_string(n).size();
    }
    vector<string> splitMessage(string s, int limit) {
        int n = s.size();
        int parts = 1, a = 1;
        while(a + n + parts * (3 + sz(parts)) > parts * limit) {
            if(3 + sz(parts) * 2 >= limit)
                return {};
            parts += 1;
            a += sz(parts);
        }
        vector<string> ans;
        int count = 1;
        for(int i = 0; i < n; ) {
            string q = "<" + to_string(count++) + "/" + to_string(parts) + ">";
            string p;
            for(int j = 0; j < limit - q.size() && i < n; j++)
                p += s[i++];
            p += q;
            ans.push_back(p);
        }
        return ans;
    }
};