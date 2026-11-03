class Solution {
public:
    int timer;
    vector<int> dt, low;

    void dfs(int u, int parU, vector<vector<int>>& adj, vector<vector<int>>& bridges) {
        dt[u] = low[u] = ++timer;

        for (int v : adj[u]) {
            if (dt[v] == -1) {
                dfs(v, u, adj, bridges);
                if (low[v] > dt[u]) {
                    bridges.push_back({u, v});
                }
                low[u] = min(low[u], low[v]);
            } else if (v != parU) {
                low[u] = min(low[u], dt[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto& c : connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }

        timer = 0;
        dt.assign(n, -1);
        low.assign(n, 0);

        vector<vector<int>> bridges;
        for (int i = 0; i < n; i++) {
            if (dt[i] == -1) {
                dfs(i, -1, adj, bridges);
            }
        }
        return bridges;
    }
};