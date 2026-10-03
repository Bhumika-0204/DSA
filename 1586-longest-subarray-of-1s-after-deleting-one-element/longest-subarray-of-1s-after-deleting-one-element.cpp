class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int lo=0,hi=0;
        int res=INT_MIN;
        int zeros=0;
        for(hi=0;hi<nums.size();hi++){
            if(nums[hi]==0) zeros++;
            while(zeros>1){
                if(nums[lo]==0){
                    zeros--;
                    

                }
                lo++;
            }
            int len=hi-lo;
            res=max(res,len);
        }
        return res;
    }
};