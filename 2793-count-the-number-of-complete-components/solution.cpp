class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            vector<int> comp;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                comp.push_back(u);
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            long long numVertices = comp.size();
            long long numEdges = 0;
            for (int u : comp) numEdges += adj[u].size();
            numEdges /= 2;
            if (numEdges == numVertices * (numVertices - 1) / 2) {
                count++;
            }
        }
        return count;
    }
};
