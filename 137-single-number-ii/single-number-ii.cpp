class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for (int bit = 0; bit < 32; bit++) {
            int cnt = 0;
            for (int x : nums) {
                if ((x >> bit) & 1)
                    cnt++;
            }
            if (cnt % 3 != 0)
                result |= (1 << bit);
        }
        return result;
    }
};
