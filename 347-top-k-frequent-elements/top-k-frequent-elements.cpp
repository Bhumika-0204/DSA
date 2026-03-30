class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> f;
        for(int x:nums){
            f[x]++;
        }
        int n=nums.size();
        vector<vector<int>> ans(n+1);
        for(auto it:f){
            int num=it.first;
            int ff=it.second;
            ans[ff].push_back(num);
        }
        vector<int> res;
        for(int i=n;i>=0 && res.size()<k;i--){
            for(int num:ans[i]){
                res.push_back(num);
                if(res.size()==k){
                    break;
                }
            }

        }
        return res;
    }
};