#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {

        const long long INF = 1e18;

        unordered_map<string,int> id;
        int idx = 0;

        // Assign ids
        for (int i = 0; i < original.size(); i++) {
            if (!id.count(original[i])) id[original[i]] = idx++;
            if (!id.count(changed[i]))  id[changed[i]]  = idx++;
        }

        int m = idx;
        vector<vector<long long>> dist(m, vector<long long>(m, INF));
        for (int i = 0; i < m; i++) dist[i][i] = 0;

        // Direct edges
        for (int i = 0; i < original.size(); i++) {
            int u = id[original[i]];
            int v = id[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Floyd–Warshall
        for (int k = 0; k < m; k++)
            for (int i = 0; i < m; i++)
                for (int j = 0; j < m; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        int n = source.size();
        vector<long long> dp(n + 1, INF);
        dp[n] = 0;

        // DP
        for (int i = n - 1; i >= 0; i--) {

            if (source[i] == target[i])
                dp[i] = dp[i + 1];

            // Try all possible substring lengths
            for (auto &p1 : id) {
                const string &s1 = p1.first;
                int len = s1.size();
                if (i + len > n) continue;

                if (source.compare(i, len, s1) != 0) continue;

                for (auto &p2 : id) {
                    const string &s2 = p2.first;
                    if (s2.size() != len) continue;
                    if (target.compare(i, len, s2) != 0) continue;

                    long long c = dist[p1.second][p2.second];
                    if (c < INF && dp[i + len] < INF)
                        dp[i] = min(dp[i], c + dp[i + len]);
                }
            }
        }

        return dp[0] >= INF ? -1 : dp[0];
    }
};
