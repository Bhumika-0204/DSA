
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int noDel = arr[0];
        int oneDel = INT_MIN;
        int res = arr[0];

        for (int i = 1; i < n; i++) {
            int prevNoDel = noDel;

            noDel = max(arr[i], noDel + arr[i]);

            oneDel = max(prevNoDel,
                         oneDel == INT_MIN ? INT_MIN : oneDel + arr[i]);

            res = max(res, max(noDel, oneDel));
        }

        return res;
    }
};
