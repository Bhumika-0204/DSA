#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // returns vector<int> to match many test harnesses that expect int vectors.
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = (int)nums.size();
        vector<int> ans;
        if (k > n) return ans;

        unordered_map<int,int> cnt;
        // initial window
        for (int i = 0; i < k; ++i) cnt[nums[i]]++;
        ans.push_back((int)calcSum(cnt, x)); // cast to int for return

        for (int i = k; i < n; ++i) {
            int left = nums[i - k];
            if (--cnt[left] == 0) cnt.erase(left);
            cnt[nums[i]]++;
            ans.push_back((int)calcSum(cnt, x));
        }
        return ans;
    }

private:
    // compute sum as long long then return it (caller casts if needed)
    long long calcSum(const unordered_map<int,int>& cnt, int x) {
        vector<pair<int,int>> pairs;
        pairs.reserve(cnt.size());
        for (auto &p : cnt) pairs.push_back({p.second, p.first}); // (freq, value)

        sort(pairs.begin(), pairs.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            if (a.first != b.first) return a.first > b.first;      // freq desc
            return a.second > b.second;                           // value desc
        });

        long long sum = 0;
        int limit = min((int)pairs.size(), x);
        for (int i = 0; i < limit; ++i) sum += 1LL * pairs[i].first * pairs[i].second;
        return sum;
    }
};
