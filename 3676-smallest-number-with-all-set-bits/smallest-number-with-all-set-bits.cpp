class Solution {
public:
    int smallestNumber(int n) {
        int bits = 0;
        int temp = n;
        while (temp > 0) {
            bits++;
            temp >>= 1;
        }
        return (1 << bits) - 1;
    }
};
