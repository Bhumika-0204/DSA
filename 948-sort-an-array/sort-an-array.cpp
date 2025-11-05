#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return nums;
        vector<int> temp(n);
        mergeSort(nums, 0, n-1, temp);
        return nums;
    }

private:
    void mergeSort(vector<int>& a, int l, int r, vector<int>& temp) {
        if (l >= r) return;
        int m = l + (r - l) / 2;
        mergeSort(a, l, m, temp);
        mergeSort(a, m+1, r, temp);
        merge(a, l, m, r, temp);
    }

    void merge(vector<int>& a, int l, int m, int r, vector<int>& temp) {
        int i = l;
        int j = m + 1;
        int k = l;
        while (i <= m && j <= r) {
            if (a[i] <= a[j]) temp[k++] = a[i++];
            else temp[k++] = a[j++];
        }
        while (i <= m) temp[k++] = a[i++];
        while (j <= r) temp[k++] = a[j++];

        for (int p = l; p <= r; ++p) {
            a[p] = temp[p];
        }
    }
};
