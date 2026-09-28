class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>f;
        int n=fruits.size();
        int lo=0,hi=0;
        int res=INT_MIN;
        for(hi=0;hi<n;hi++){
            f[fruits[hi]]++;
            while(f.size()>2){
                f[fruits[lo]]--;
                if(f[fruits[lo]]==0) f.erase(fruits[lo]);
                lo++;
            }
            int len=hi-lo+1;
            res=max(res,len);
        }
        return res;
    }
};