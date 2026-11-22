
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<int> last(26, -1);
        vector<int> old(n);

        // DFS on original tree
        vector<pair<int, int>> st;
        st.push_back({0, 0});

        while (!st.empty()) {
            auto [u, state] = st.back();
            st.pop_back();

            int c = s[u] - 'a';

            if (state == 0) {
                old[u] = last[c];

                if (last[c] != -1)
                    newParent[u] = last[c];

                last[c] = u;

                st.push_back({u, 1});

                for (int v : adj[u])
                    st.push_back({v, 0});
            }
            else {
                last[c] = old[u];
            }
        }

        // Build modified tree
        vector<vector<int>> tree(n);

        for (int i = 1; i < n; i++) {
            tree[newParent[i]].push_back(i);
        }

        // Calculate subtree sizes
        vector<int> ans(n, 1);
        vector<int> order = {0};

        for (int i = 0; i < order.size(); i++) {
            int u = order[i];

            for (int v : tree[u])
                order.push_back(v);
        }

        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            ans[newParent[u]] += ans[u];
        }

        return ans;
    }
};
