class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges) adj[e[0]].push_back({e[1], e[2]});

        const long long INF = LLONG_MAX / 4;
        // dist[node][run], run in 1..k
        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));

        // (distance, node, run)
        using T = tuple<long long, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, r] = pq.top();
            pq.pop();
            if (d > dist[u][r]) continue;

            for (auto& [v, w] : adj[u]) {
                int nr = (labels[v] == labels[u]) ? r + 1 : 1;
                if (nr > k) continue;
                long long nd = d + w;
                if (nd < dist[v][nr]) {
                    dist[v][nr] = nd;
                    pq.push({nd, v, nr});
                }
            }
        }

        long long ans = INF;
        for (int r = 1; r <= k; r++) ans = min(ans, dist[n - 1][r]);
        return ans >= INF ? -1 : (int)ans;
    }
};