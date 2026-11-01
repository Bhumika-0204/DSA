class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        int nodel=arr[0];
        int onedel=INT_MIN;
        int res=arr[0];

        for(int i=1;i<n;i++){
            int prevnodel=nodel;

            nodel=max(nodel+arr[i],arr[i]);

            onedel=max(prevnodel , onedel==INT_MIN?INT_MIN:onedel+arr[i]);
            res=max(res,max(onedel,nodel));
        }
        return res;
    }
};