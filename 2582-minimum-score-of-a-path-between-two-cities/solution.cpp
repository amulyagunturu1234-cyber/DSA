class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1); // adj[u] = {v, dist}
        for (auto& r : roads) {
            int a = r[0], b = r[1], d = r[2];
            adj[a].push_back({b, d});
            adj[b].push_back({a, d});
        }

        vector<bool> visited(n + 1, false);
        int ans = INT_MAX;

        // BFS/DFS from city 1, take min distance over all edges reachable
        queue<int> q;
        q.push(1);
        visited[1] = true;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto& [v, d] : adj[u]) {
                ans = min(ans, d);
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        return ans;
    }
};
