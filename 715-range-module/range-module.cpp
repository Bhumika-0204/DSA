class RangeModule {
public:
    map<int,int> mp;

    RangeModule() {

    }

    void addRange(int left, int right) {
        auto it = mp.lower_bound(left);

        if(it != mp.begin()) {
            auto prev = std::prev(it);

            if(prev->second >= left) {
                it = prev;
            }
        }

        int L = left;
        int R = right;

        while(it != mp.end() && it->first <= R) {
            L = min(L, it->first);
            R = max(R, it->second);

            it = mp.erase(it);
        }

        mp[L] = R;
    }

    bool queryRange(int left, int right) {
        auto it = mp.upper_bound(left);

        if(it == mp.begin()) {
            return false;
        }

        --it;

        return it->first <= left && it->second >= right;
    }

    void removeRange(int left, int right) {
        auto it = mp.lower_bound(left);

        if(it != mp.begin()) {
            auto prev = std::prev(it);

            if(prev->second > left) {
                it = prev;
            }
        }

        vector<pair<int,int>> temp;

        while(it != mp.end() && it->first < right) {
            int L = it->first;
            int R = it->second;

            // Preserve left remaining portion
            if(L < left) {
                temp.push_back({L, left});
            }

            // Preserve right remaining portion
            if(R > right) {
                temp.push_back({right, R});
            }

            it = mp.erase(it);
        }

        for(auto p : temp) {
            mp[p.first] = p.second;
        }
    }
};