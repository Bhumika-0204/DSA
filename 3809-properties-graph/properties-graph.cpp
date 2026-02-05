class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) parent[b] = a;
    }

    int intersectCount(vector<int>& a, vector<int>& b) {
        vector<int> freq(101, 0);
        for (int x : a) freq[x] = 1;

        int cnt = 0;
        for (int x : b) {
            if (freq[x] == 1) {
                cnt++;
                freq[x] = 2; // ensure distinct counting
            }
        }
        return cnt;
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        parent.resize(n);

        for (int i = 0; i < n; i++) parent[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (intersectCount(properties[i], properties[j]) >= k) {
                    unite(i, j);
                }
            }
        }

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i) components++;
        }
        return components;
    }
};
