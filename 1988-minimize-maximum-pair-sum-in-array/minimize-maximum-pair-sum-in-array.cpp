class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        int maxsum=0;
        while(i<j){
            int curr=nums[i]+nums[j];
            maxsum=max(maxsum,curr);
            i++;
            j--;
        }
        return maxsum;

    }
};