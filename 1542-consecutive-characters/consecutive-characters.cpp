class Solution {
public:
    int maxPower(string s) {
        int cnt=1;
        int res=1;
        for(int i=1;i<s.size();i++){
            if(s[i-1]==s[i]){
                cnt++;
                res=max(res,cnt);
            }
            else cnt=1;

        }
        return res;
    }
};