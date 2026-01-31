class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",
            ".---","-.-",".-..","--","-.","---",".--.","--.-",
            ".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };

        unordered_set<string> st;

        for (string &w : words) {
            string code = "";
            for (char c : w) {
                code += morse[c - 'a'];
            }
            st.insert(code);
        }
        return st.size();
    }
};
