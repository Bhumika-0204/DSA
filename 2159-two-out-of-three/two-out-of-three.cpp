class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        unordered_set<int> s3(nums3.begin(), nums3.end());

        vector<int> res;
        for (int x = 1; x <= 100; x++) {
            int count = 0;
            if (s1.count(x)) count++;
            if (s2.count(x)) count++;
            if (s3.count(x)) count++;
            if (count >= 2) res.push_back(x);
        }
        return res;
    }
};

