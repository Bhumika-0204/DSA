class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int x=INT_MAX;
        bool y=false;


        for(int a:nums1){
            if(a%2){
                y=true;
                x=min(x,a);
            }
        }
        if(!y) return true;
        
        for(int a: nums1){
            if(a%2==0 && a<=x){
                return false;
            }
        }
        return true;
    }
};