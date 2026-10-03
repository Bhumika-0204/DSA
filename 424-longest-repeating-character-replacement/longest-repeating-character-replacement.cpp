class Solution {
public:
    int find(vector<int>&f){
        int maxcnt=-1;
        for(int i=0;i<f.size();i++){
            if(f[i]>maxcnt) maxcnt=f[i];
        }
        return maxcnt;
    }
    int characterReplacement(string s, int k) {
        int lo=0,hi=0;
        int res=INT_MIN;
        vector<int>f(256,0);
        for(hi=0;hi<s.size();hi++){
            f[s[hi]]++;
            int len=hi-lo+1;
            int maxc=find(f);
            int diff=len-maxc;
            while(diff>k){
                f[s[lo]]--;
                lo++;
                maxc=find(f);
                len=hi-lo;
                diff=len-maxc;
            }
            len=hi-lo+1;
            res=max(res,len);
        }
        return res;
    }
};