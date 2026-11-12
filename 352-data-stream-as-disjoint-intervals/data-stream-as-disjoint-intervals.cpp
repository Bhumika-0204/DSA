class SummaryRanges {
public:
    map<int,int> mp;

    SummaryRanges() {

    }

    void addNum(int value) {

        auto it = mp.upper_bound(value);

        // Check previous interval
        if(it != mp.begin()) {
            auto prev = std::prev(it);

            // Already present
            if(prev->second >= value) {
                return;
            }

            // Extend previous interval
            if(prev->second + 1 == value) {
                prev->second = value;

                // Merge with next interval if adjacent
                if(it != mp.end() && it->first == value + 1) {
                    prev->second = it->second;
                    mp.erase(it);
                }

                return;
            }
        }

        // Connect with next interval
        if(it != mp.end() && it->first == value + 1) {
            int end = it->second;
            mp.erase(it);
            mp[value] = end;
            return;
        }

        // Create a new interval
        mp[value] = value;
    }

    vector<vector<int>> getIntervals() {

        vector<vector<int>> res;

        for(auto it : mp) {
            res.push_back({it.first, it.second});
        }

        return res;
    }
};