class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return 1;
        sort(nums.begin(),nums.end());
        int ans=1;
        int res=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==nums[i]) continue ;
            else if(nums[i]==nums[i-1]+1) ans++;
            else ans=1;
            res=max(ans,res);

    
        }
        return res;
    }
};