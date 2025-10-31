class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size() - 2;
        vector<int> count(n, 0);
        vector<int> ans;

        for (int x : nums) {
            count[x]++;
            if (count[x] == 2)
                ans.push_back(x);
        }
        return ans;
    }
};
