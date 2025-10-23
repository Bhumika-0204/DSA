#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        vector<int> arr;
        for(char c : s) arr.push_back(c - '0');
        while(arr.size() > 2) {
            vector<int> temp;
            for(int i = 0; i < arr.size() - 1; i++) {
                temp.push_back((arr[i] + arr[i + 1]) % 10);
            }
            arr = temp;
        }

        return arr[0] == arr[1];
    }
};
