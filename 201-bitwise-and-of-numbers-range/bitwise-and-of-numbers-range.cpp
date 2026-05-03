class Solution {
public:
    int msb_index(int n) {
        int ans = 0;
        while (n > 0) {
            n /= 2;
            ans++;
        }
        return ans;
    }

    int rangeBitwiseAnd(int left, int right) {
        int left_msb = msb_index(left), right_msb = msb_index(right);
        if (left_msb != right_msb) return 0;
        int zero_msb = -1, curr = 1;
        int right_ = right;
        while (left > 0) {
            int index = 1 << curr;
            if ((left & 1) == 0 && (right_ & 1) == 1) {
                zero_msb = curr;
            }
            curr++;
            left >>= 1;
            right_ >>= 1;
        }
        right_ = right;
        for (int i = 0; i < zero_msb; i++) {
            int index = 1 << i;
            if ((right_ & 1) == 1) right -= index;
            right_ >>= 1;
        }
        return right;
    }
};