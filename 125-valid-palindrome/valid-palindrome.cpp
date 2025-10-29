class Solution {
public:
    bool isPalindrome(string s) {
        string ss="";
        for(char c:s){
            if(isalnum(c)){
                ss.push_back(tolower(c));
            }
        }
        int n=ss.length();
        string ans="";
        for(int i=n-1;i>=0;i--){
            ans.push_back(ss[i]);
        }
        return ss==ans;
    }
};