class Solution {
public:

    long long dfs(int node,
                  vector<vector<int>>& adj,
                  vector<bool>& vis) {

        vis[node] = true;

        long long cnt = 1;

        for(auto neighbour : adj[node]) {

            if(!vis[neighbour]) {
                cnt += dfs(neighbour, adj, vis);
            }
        }

        return cnt;
    }

    long long countPairs(int n,
                         vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);

        long long ans = 0;
        long long remaining = n;

        for(int i = 0; i < n; i++) {

            if(!vis[i]) {

                long long size =
                    dfs(i, adj, vis);

                ans += size * (remaining - size);

                remaining -= size;
            }
        }

        return ans;
    }
};