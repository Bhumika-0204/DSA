class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string ans = s;
        unordered_set<string> seen;
        queue<string> q;
        q.push(s);
        seen.insert(s);
        
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            // update minimum
            if (cur < ans) ans = cur;
            
            // Operation 1: Add to odd indices
            string t1 = cur;
            for (int i = 1; i < t1.size(); i += 2) {
                int digit = (t1[i] - '0' + a) % 10;
                t1[i] = char('0' + digit);
            }
            if (!seen.count(t1)) {
                seen.insert(t1);
                q.push(t1);
            }
            
            // Operation 2: Rotate by b to the right
            string t2 = cur.substr(cur.size() - b) + cur.substr(0, cur.size() - b);
            if (!seen.count(t2)) {
                seen.insert(t2);
                q.push(t2);
            }
        }
        
        return ans;
    }
};