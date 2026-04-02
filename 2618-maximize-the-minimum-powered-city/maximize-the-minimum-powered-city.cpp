class Solution {
public:
    typedef long long ll;

    bool canAchieve(vector<int>& stations, int r, ll k, ll target) {
        int n = stations.size();

        vector<ll> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stations[i];
        }

        vector<ll> power(n);
        for (int i = 0; i < n; i++) {
            int left = max(0, i - r);
            int right = min(n - 1, i + r);
            power[i] = prefix[right + 1] - prefix[left];
        }

        vector<ll> added(n, 0);
        ll used = 0, currAdd = 0;

        for (int i = 0; i < n; i++) {
            if (i - r - 1 >= 0) currAdd -= added[i - r - 1];

            ll currPower = power[i] + currAdd;

            if (currPower < target) {
                ll need = target - currPower;
                used += need;
                if (used > k) return false;

                currAdd += need;

                int pos = min(n - 1, i + r);
                added[pos] += need;
            }
        }

        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        ll low = 0, high = 1e18, ans = 0;

        while (low <= high) {
            ll mid = (low + high) / 2;

            if (canAchieve(stations, r, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};