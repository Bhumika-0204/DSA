class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        unordered_map<char, int> f;

        int lo = 0;

        for(int hi = 0; hi < s2.size(); hi++) {
            f[s2[hi]]++;

            if(hi - lo + 1 > s1.size()) {

                f[s2[lo]]--;

                if(f[s2[lo]] == 0)
                    f.erase(s2[lo]);

                lo++;
            }
            if(hi - lo + 1 == s1.size()) {

                unordered_map<char, int> temp;

                for(char c : s1)
                    temp[c]++;

                if(f == temp)
                    return true;
            }
        }

        return false;
    }
};