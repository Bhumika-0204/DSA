class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int,int>> v;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());

        int left = 0;
        int right = n - 1;

        while(left < right) {
            
            int sum = v[left].first + v[right].first;

            if(sum == target) {
                return {v[left].second, v[right].second};
            }
            else if(sum < target) {
                left++;
            }
            else {
                right--;
            }
        }   

        return {-1, -1};  

    }     
};        