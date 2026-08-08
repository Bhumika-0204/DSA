class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int>v(n);
        for(int i=0;i<k;i++){
            v[i]=nums[n-k+i];
        }
        for(int i=k;i<n;i++){
            v[i]=nums[i-k];
        }
        nums=v;
    }
};