class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        int nodel=arr[0];
        int onedel=INT_MIN;
        int res=arr[0];

        for(int i=1;i<n;i++){
            int x=nodel;
            nodel=max(arr[i],nodel+arr[i]);

            onedel=max(x,onedel==INT_MIN?INT_MIN:onedel+arr[i]);
            res=max(res,max(onedel,nodel));
        }
        return res;
    }
};