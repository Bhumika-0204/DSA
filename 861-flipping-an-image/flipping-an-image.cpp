class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        
        for (int i = 0; i < n; i++) {
            int l = 0, r = image[i].size() - 1;

            while (l <= r) {
                // swap + invert
                int left = image[i][l] ^ 1;
                int right = image[i][r] ^ 1;

                image[i][l] = right;
                image[i][r] = left;

                l++;
                r--;
            }
        }

        return image;
    }
};
