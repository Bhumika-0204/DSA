class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int x=0;
        for(string s:patterns){
            if(word.find(s)!=string::npos){
                x++;
            }
        }
        return x;
    }
};