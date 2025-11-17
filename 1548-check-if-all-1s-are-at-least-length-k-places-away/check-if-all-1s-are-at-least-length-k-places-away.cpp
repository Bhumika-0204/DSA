class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last = -1; // last 1 ka index
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (last != -1 && i - last - 1 < k) {
                    return false;
                }
                last = i;
            }
        }
        return true;
    }
};