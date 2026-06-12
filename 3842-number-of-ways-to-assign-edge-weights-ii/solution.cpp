class Solution {
public:
    const int MOD = 1e9 + 7;
    const int LOG = 18;

    vector<vector<int>> up;
    vector<int> depth;
    vector<vector<int>> adj;
    int n;

    void dfs(int u, int parent, int d) {
        depth[u] = d;
        up[u][0] = parent;
        for (int i = 1; i < LOG; i++)
            up[u][i] = up[up[u][i-1]][i-1];
        for (int v : adj[u]) {
            if (v != parent)
                dfs(v, u, d + 1);
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int i = 0; i < LOG; i++)
            if ((diff >> i) & 1)
                u = up[u][i];
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; i--)
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        return up[u][0];
    }

    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n = edges.size() + 1;
        adj.assign(n + 1, {});
        up.assign(n + 1, vector<int>(LOG, 0));
        depth.assign(n + 1, 0);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(1, 0, 0);

        vector<int> ans;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            int l = lca(u, v);
            int k = depth[u] + depth[v] - 2 * depth[l]; // number of edges on path

            if (k == 0) {
                // same node, no edges — cost is 0 (even), no valid assignment
                ans.push_back(0);
            } else {
                // 2^(k-1) mod MOD
                ans.push_back((int)power(2, k - 1, MOD));
            }
        }
        return ans;
    }
};
