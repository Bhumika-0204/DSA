class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int lo=0;
        int hi=0;
        int res=0;
        int zeros=0;
        for(int hi=0;hi<n;hi++){
            if(nums[hi]==0) zeros++;
            while(zeros>k){
                if(nums[lo]==0) zeros--;
                lo++;
            }
            int len=hi-lo+1;
            res=max(res,len);
        }
        return res;
    }
};