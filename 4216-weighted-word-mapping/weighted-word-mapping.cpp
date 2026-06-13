class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(string word: words){
            int w=0;
            for(char ch: word){
                w += weights[ch-'a'];
            }
            ans += (char)((25 - w%26) + 'a');
        }
        return ans;
    }
};