class Solution {
    private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& suspicious) {
        suspicious[node] = true;

        for (int i : adj[node]) {
            if (!suspicious[i]) {
                dfs(i, adj, suspicious);
            }
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        for(auto it:invocations){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        vector<bool> suspicious(n,false);
        dfs(k, adj, suspicious);
        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            if (!suspicious[u] && suspicious[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }
        return ans;
    }
};