class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0;
        int maxl=1;
        for(int i=0;i<n;i++){
            while((long long)nums[i] > (long long)nums[l]*k){
                l++;
            }
            maxl=max(maxl,i-l+1);
        }
        return n-maxl;
    }
};