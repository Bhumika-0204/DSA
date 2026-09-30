class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int lo=0,hi=0;
        int res=INT_MIN;
        int zeros=0;
        for(hi=0;hi<n;hi++){
            if(nums[hi]==0) zeros++;

            int len=hi-lo+1;

            while(zeros>k){
                  if(nums[lo]==0) zeros--;
                  lo++;
            

            }
             len=hi-lo+1;
             res=max(res,len);
 
        }
        

        return res;
    }

};