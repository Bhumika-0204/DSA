#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int num : nums) {
            if(num % k == 0)
                freq[num]++;
        }
        
        int m = 1;
        while(true) {
            int multiple = m * k;
            if(freq.find(multiple) == freq.end())
                return multiple;
            m++;
        }
    }
};
