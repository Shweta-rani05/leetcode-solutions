class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int u, int v) {

        int pu = find(u);
        int pv = find(v);

        // Already connected -> cycle
        if (pu == pv)
            return false;

        // Union by rank
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        // Initially every node is its own parent
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            // If union fails, u and v are already connected
            if (!unite(u, v)) {
                return {u, v};
            }
        }

        return {};
    }
};