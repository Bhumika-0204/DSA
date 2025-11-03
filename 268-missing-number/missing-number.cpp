class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int temp=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>temp) temp=nums[i];
        }
        for(int i=0;i<temp;i++){
            if(find(nums.begin(), nums.end(), i) == nums.end()) return i;

        }
        return temp+1;
    }
};