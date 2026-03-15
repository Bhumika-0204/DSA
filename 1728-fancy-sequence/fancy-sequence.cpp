class Fancy {
    vector<long long> arr;
    long long mul = 1;
    long long add = 0;
    const long long MOD = 1000000007;

    long long modInverse(long long x) {
        long long res = 1, power = MOD - 2;
        x %= MOD;

        while (power) {
            if (power & 1) res = (res * x) % MOD;
            x = (x * x) % MOD;
            power >>= 1;
        }
        return res;
    }

public:

    void append(int val) {
        long long normalized = ((val - add + MOD) % MOD * modInverse(mul)) % MOD;
        arr.push_back(normalized);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= arr.size()) return -1;
        return (arr[idx] * mul + add) % MOD;
    }
};