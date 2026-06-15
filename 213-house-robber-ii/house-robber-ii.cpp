class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];

        int dp[n];
        //0 to n-1 tak jaenge

        dp[0]=nums[0];
        if(n!=1) dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n-1;i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        int max1=dp[n-2];
        //1 to n-1 index tk jaega
        dp[1]=nums[1];
        if(n!=2) dp[2]=max(nums[1],nums[2]);
        for(int i=3;i<n;i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        int max2=dp[n-1];
        return max(max1,max2);
    }
};