class Solution {
public:
    int racecar(int target) {
        queue<pair<int,int>> q;
        unordered_set<long long> vis;

        q.push({0, 1});
        vis.insert(encode(0, 1));

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [pos, speed] = q.front();
                q.pop();

                if (pos == target) return steps;

                // Accelerate
                int npos = pos + speed;
                int nspeed = speed * 2;
                if (abs(npos) <= 2 * target) {
                    long long key = encode(npos, nspeed);
                    if (!vis.count(key)) {
                        vis.insert(key);
                        q.push({npos, nspeed});
                    }
                }

                // Reverse
                nspeed = speed > 0 ? -1 : 1;
                long long key = encode(pos, nspeed);
                if (!vis.count(key)) {
                    vis.insert(key);
                    q.push({pos, nspeed});
                }
            }
            steps++;
        }
        return -1;
    }

private:
    long long encode(int pos, int speed) {
        return ((long long)(pos) << 32) ^ (unsigned int)(speed);
    }
};