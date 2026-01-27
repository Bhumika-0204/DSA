class Solution {
public:
    long long minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, long long>>> adj(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            long long w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2LL * w});
        }
        const long long INF = LLONG_MAX;
        vector<long long> dist(n, INF);
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (cost > dist[u]) continue;

            for (auto &it : adj[u]) {
                int v = it.first;
                long long w = it.second;
                if (dist[v] > cost + w) {
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1] == INF ? -1 : dist[n - 1];
    }
};
