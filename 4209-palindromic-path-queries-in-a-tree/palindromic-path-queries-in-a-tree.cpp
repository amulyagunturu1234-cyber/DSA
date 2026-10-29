class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        vector<vector<int>> up(LOG + 1, vector<int>(n, 0));
        vector<int> depth(n, 0), tin(n), tout(n);

        // iterative DFS
        int timer = 0;
        vector<int> it(n, 0), st;
        st.push_back(0);
        up[0][0] = 0;
        tin[0] = timer++;
        while (!st.empty()) {
            int u = st.back();
            if (it[u] < (int)adj[u].size()) {
                int v = adj[u][it[u]++];
                if (v == up[0][u] && u != 0) continue;
                if (u == 0 && v == 0) continue;
                up[0][v] = u;
                depth[v] = depth[u] + 1;
                tin[v] = timer++;
                st.push_back(v);
            } else {
                tout[u] = timer - 1;
                st.pop_back();
            }
        }
        for (int j = 1; j <= LOG; j++)
            for (int i = 0; i < n; i++)
                up[j][i] = up[j - 1][up[j - 1][i]];

        auto lca = [&](int a, int b) {
            if (depth[a] < depth[b]) swap(a, b);
            int diff = depth[a] - depth[b];
            for (int j = 0; j <= LOG; j++)
                if (diff >> j & 1) a = up[j][a];
            if (a == b) return a;
            for (int j = LOG; j >= 0; j--)
                if (up[j][a] != up[j][b]) {
                    a = up[j][a];
                    b = up[j][b];
                }
            return up[0][a];
        };

        // Fenwick tree with XOR: range update, point query
        vector<int> bit(n + 2, 0);
        auto upd = [&](int i, int v) {
            for (i++; i <= n + 1; i += i & -i) bit[i] ^= v;
        };
        auto qry = [&](int i) {
            int r = 0;
            for (i++; i > 0; i -= i & -i) r ^= bit[i];
            return r;
        };
        auto rangeXor = [&](int l, int r, int v) {
            upd(l, v);
            upd(r + 1, v);
        };

        for (int i = 0; i < n; i++)
            rangeXor(tin[i], tout[i], 1 << (s[i] - 'a'));

        vector<bool> ans;
        for (auto& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u; char c;
                ss >> u >> c;
                int delta = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));
                s[u] = c;
                rangeXor(tin[u], tout[u], delta);
            } else {
                int u, v;
                ss >> u >> v;
                int l = lca(u, v);
                int mask = qry(tin[u]) ^ qry(tin[v]) ^ (1 << (s[l] - 'a'));
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }
        return ans;
    }
};