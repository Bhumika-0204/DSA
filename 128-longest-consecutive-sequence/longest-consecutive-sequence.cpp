class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int ans=1;
        int res=1;
        for(int i=1;i<nums.size();i++){
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            else if(nums[i]==nums[i-1]+1) ans++;
            else ans=1;
            res=max(res,ans);
        }
        return res;
    }
};