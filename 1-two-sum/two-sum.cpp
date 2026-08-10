class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>>mp;
        for(int i=0;i<n;i++){
            mp.push_back({nums[i],i});
        }
        sort(mp.begin(),mp.end());
        int left=0,right=n-1;
        while(left<right){
            int sum=mp[left].first + mp[right].first;
            if(sum ==target){
                return {mp[left].second , mp[right].second};
            }
            else if(sum<target){
                left++;
            }
            else right--;
        }
        return {-1,-1};
    }
};