class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int lo=0;
        int res=INT_MIN;
        unordered_map<int,int>f;
        for(int hi=0;hi<fruits.size();hi++){
            f[fruits[hi]]++;
            while(f.size()>2){
                  f[fruits[lo]]--;
                  lo++;
                  if(f[fruits[lo-1]]==0){
                  f.erase(fruits[lo-1]);
                  }
            }
            int len=hi-lo+1;
            res=max(res,len);
        }
        
        
        return res;
    }
};