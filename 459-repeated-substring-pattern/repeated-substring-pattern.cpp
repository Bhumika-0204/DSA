class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        string mid = t.substr(1, t.size() - 2);
        return mid.find(s) != string::npos;
    }
};
