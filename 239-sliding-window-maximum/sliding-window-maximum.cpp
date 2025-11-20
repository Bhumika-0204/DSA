class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int ngi[n];
        stack<int> st;
        ngi[n-1]=n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 &&nums[st.top()]<nums[i]){
                st.pop();

            }
            if(st.size()==0) ngi[i]=n;
            else ngi[i]=st.top();
            st.push(i);

        }
        vector<int> ans;
        for(int i=0;i<n-k+1;i++){
            int mx=nums[i];
            int j=i;
            while(j<i+k){
                mx=nums[j];
                j=ngi[j];
            }
            ans.push_back(mx);
        }
        return ans;
    }
};