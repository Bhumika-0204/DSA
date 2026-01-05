class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int negCount = 0;
        int minAbs = INT_MAX;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                int val = matrix[i][j];
                if (val < 0) negCount++;
                sum += abs(val);
                minAbs = min(minAbs, abs(val));
            }
        }

        if (negCount % 2 == 1) {
            sum -= 2LL * minAbs;
        }

        return sum;
    }
};
