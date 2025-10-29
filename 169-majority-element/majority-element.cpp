#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();

        for (int num : nums) {
            freq[num]++;
        }

        for (auto &p : freq) {
            if (p.second > n / 2) {
                return p.first;
            }
        }

        return -1; 
    }
};
