class Solution {
public:

    bool isPossible(vector<int>& ranks, int cars, long long mid) {

        long long total = 0;

        for(int i = 0; i < ranks.size(); i++) {

            long long n = sqrt((long double)mid / ranks[i]);

            total += n;

            if(total >= cars) {
                return true;
            }
        }

        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {

        long long low = 1;

        int mini = *min_element(ranks.begin(), ranks.end());

        long long high = 1LL * mini * cars * cars;

        long long ans = high;

        while(low <= high) {

            long long mid = low + (high - low) / 2;

            if(isPossible(ranks, cars, mid)) {

                ans = mid;
                high = mid - 1;

            }
            else {

                low = mid + 1;
            }
        }

        return ans;
    }
};