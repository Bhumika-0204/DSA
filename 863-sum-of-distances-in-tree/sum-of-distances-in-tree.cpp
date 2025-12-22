class Solution {
public:
    vector<vector<int>> graph;
    vector<int> count;
    vector<int> ans;
    int n;

    void dfs1(int u, int parent) {
        for (int v : graph[u]) {
            if (v == parent) continue;
            dfs1(v, u);
            count[u] += count[v];
            ans[0] += ans[v] + count[v];
        }
    }

    void dfs2(int u, int parent) {
        for (int v : graph[u]) {
            if (v == parent) continue;
            ans[v] = ans[u] - count[v] + (n - count[v]);
            dfs2(v, u);
        }
    }

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        n = N;
        graph.resize(n);
        count.assign(n, 1);
        ans.assign(n, 0);

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        dfs1(0, -1);   // postorder
        dfs2(0, -1);   // rerooting

        return ans;
    }
};
