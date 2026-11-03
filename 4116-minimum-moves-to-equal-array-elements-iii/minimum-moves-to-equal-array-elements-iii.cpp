class Solution {
public:
    int maxNum(vector<int>&nums){
        int ans=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>ans){
                ans=nums[i];
            }
        }
        return ans;
    }
    int sumarray(vector<int> &nums){
        int res=0;
        for(int i=0;i<nums.size();i++){
            res+=nums[i];
        }
        return res;
    }
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        vector<int> s;
        int maxnumm=maxNum(nums);
        for(int i=0;i<n;i++){
            int count=0;
            int temp=maxnumm-nums[i];
            for(int j=0;j<temp;j++){
                nums[i]+=1;
                count++;
                
            }
            s.push_back(count);
        }
        int x=sumarray(s);
        return x;
    }
};