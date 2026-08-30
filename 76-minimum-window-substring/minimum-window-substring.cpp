class Solution {
public:
    string minWindow(string s, string t) {

        if(t.length() > s.length()) return "";

        unordered_map<char, int> mp;

        for(char c : t){
            mp[c]++;
        }

        int l = 0, r = 0;
        int start = 0;
        int minLen = INT_MAX;

        int temp = t.length();

        while(r < s.length()){

            char ch = s[r];

            if(mp.find(ch) != mp.end() && mp[ch] > 0){
                temp--;
            }

            mp[ch]--;
            r++;

            while(temp == 0){

                if(r - l < minLen){
                    start = l;
                    minLen = r - l;
                }

                char c = s[l];

                mp[c]++;

                if(mp[c] > 0){
                    temp++;
                }

                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};