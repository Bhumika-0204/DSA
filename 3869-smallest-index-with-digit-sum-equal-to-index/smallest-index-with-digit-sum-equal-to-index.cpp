class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int x=nums[i],di=0;
            for(;x>0;x/=10){
                di+=x%10;
            }
            if(di==i) return i;
        }
        return -1;
    }
};