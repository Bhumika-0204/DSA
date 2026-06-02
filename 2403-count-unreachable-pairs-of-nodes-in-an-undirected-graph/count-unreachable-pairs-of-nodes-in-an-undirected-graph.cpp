class Solution {
public:

    void dfs(vector<int> adj[], int src,
             vector<bool>& vis, int& counter) {

        vis[src] = true;
        counter++;

        for(auto neighbour : adj[src]) {
            if(!vis[neighbour]) {
                dfs(adj, neighbour, vis, counter);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {

        vector<int> adj[n];

        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        vector<int> compSizes;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                int cnt = 0;
                dfs(adj, i, vis, cnt);
                compSizes.push_back(cnt);
            }
        }

        long long res = 0;
        long long total = 0;

        for(int sz : compSizes) {
            res += 1LL * sz * (n - total - sz);
            total += sz;
        }

        return res;
    }
};