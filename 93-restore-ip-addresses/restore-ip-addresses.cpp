class Solution {
public:

    bool isValidSegment(string segment) {
        int len = segment.length();
        if (len == 0 || len > 3) return false;
        if (len > 1 && segment[0] == '0') return false;
        if (stoi(segment) > 255) return false;

        return true;
    }

    void backtrack(vector<string>& result, string current, int index, string& s, int dotCount) {
        if (dotCount == 3) {
            string lastSegment = s.substr(index);
            if (isValidSegment(lastSegment)) {
                result.push_back(current + lastSegment);
            }
            return;
        }

        int n = s.length();

        for (int i = index; i < n && i < index + 3; i++) {
            string segment = s.substr(index, i - index + 1);

            if (isValidSegment(segment)) {

                backtrack(result, current + segment + ".", i + 1, s, dotCount + 1);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string current = "";

        backtrack(result, current, 0, s, 0);

        return result;
    }
};