class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int j = 0; j < n; ++ j) 
            nums[j] %= n;
        for (int j = 0; j < n; ++ j) {
            int i = j, last_i = 0;
            bool is_forward = nums[i] > 0;
            while (nums[i] % n != 0 && nums[i] > 0 == is_forward) {
                last_i = i;
                i = (i + nums[i] + n) % n;
                nums[last_i] = (j + 1) * n;
                if (nums[i] == (j + 1) * n) 
                    return true;
            }
        }
        return false;
    }
};