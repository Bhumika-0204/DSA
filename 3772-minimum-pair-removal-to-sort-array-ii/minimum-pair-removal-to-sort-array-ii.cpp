#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Pair {
        long long sum;
        int idx;
        Pair(long long s, int i) : sum(s), idx(i) {}
    };

    int n;
    vector<bool> alive;
    vector<int> left, right;
    vector<long long> val;
    int inversions;

    struct Cmp {
        bool operator()(const Pair& a, const Pair& b) const {
            if (a.sum != b.sum) return a.sum > b.sum;   // min-heap
            return a.idx > b.idx;
        }
    };

    priority_queue<Pair, vector<Pair>, Cmp> pq;

    void init(vector<int>& nums) {
        n = nums.size();
        alive.assign(n, true);
        left.resize(n);
        right.resize(n);
        val.resize(n);
        inversions = 0;

        while (!pq.empty()) pq.pop();

        for (int i = 0; i < n; i++) {
            left[i] = i - 1;
            right[i] = i + 1;
            val[i] = nums[i];
        }
        right[n - 1] = n;

        for (int i = 0; i < n - 1; i++) {
            if (val[i] > val[i + 1]) inversions++;
            pq.emplace(val[i] + val[i + 1], i);
        }
    }

    bool isSorted() {
        return inversions == 0;
    }

    int topElement() {
        while (!pq.empty()) {
            auto p = pq.top();
            int i = p.idx;

            if (!alive[i] || right[i] == n ||
                val[i] + val[right[i]] != p.sum) {
                pq.pop();
            } else {
                break;
            }
        }
        if (pq.empty()) return -1;
        return pq.top().idx;
    }

    void mergePair(int i) {
        int j = right[i];
        if (j == n) return;

        int x = left[i];
        int y = right[j];

        // remove old inversions
        if (val[i] > val[j]) inversions--;
        if (x != -1 && val[x] > val[i]) inversions--;
        if (y != n && val[j] > val[y]) inversions--;

        long long merged = val[i] + val[j];

        // add new inversions
        if (x != -1 && val[x] > merged) inversions++;
        if (y != n && merged > val[y]) inversions++;

        // merge
        val[i] = merged;
        alive[j] = false;

        right[i] = y;
        if (y != n) {
            left[y] = i;
            pq.emplace(val[i] + val[y], i);
        }
        if (x != -1) {
            pq.emplace(val[x] + val[i], x);
        }
    }

    int minimumPairRemoval(vector<int>& nums) {
        init(nums);
        int ans = 0;

        while (!isSorted()) {
            int pos = topElement();
            mergePair(pos);
            ans++;
        }
        return ans;
    }
};
