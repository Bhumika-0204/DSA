class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        int res=INT_MAX;
        for(int i=0;i<n;i++){
            if(words[i]==target){
                int diff=abs(i-startIndex);
                int dist=min(diff,n-diff);
                res=min(res,dist);
            }
        }
        return (res==INT_MAX) ?-1:res;
    }
};