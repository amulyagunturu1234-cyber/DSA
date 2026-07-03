class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>> adj(n); // to, cost
        vector<int> costs;
        for (auto &e : edges) {
            int u = e[0], v = e[1], c = e[2];
            adj[u].push_back({v, c});
            costs.push_back(c);
        }
        
        sort(costs.begin(), costs.end());
        costs.erase(unique(costs.begin(), costs.end()), costs.end());
        
        // Check if there's a valid path where all edges have cost >= threshold,
        // total cost <= k, all intermediate nodes online
        auto canAchieve = [&](int threshold) -> bool {
            // Dijkstra-like: find minimum total cost path from 0 to n-1
            // using only edges with cost >= threshold, intermediate nodes online
            vector<long long> dist(n, LLONG_MAX);
            dist[0] = 0;
            priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
            pq.push({0, 0});
            
            while (!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                if (d > dist[u]) continue;
                if (u == n - 1) continue; // n-1 doesn't need to be online, but we don't extend past it in terms of "intermediate" check needed only for outgoing
                for (auto &[v, c] : adj[u]) {
                    if (c < threshold) continue;
                    // u must be online if u is intermediate (u != 0), 
                    // but since we're extending FROM u, and u could be 0 (always online) 
                    // or an intermediate node - if u != 0 and u != n-1, must check online
                    // Actually since we only reach u if valid, we check v's validity when using it as intermediate later
                    if (v != n - 1 && !online[v]) continue; // v must be online if it's intermediate
                    long long nd = d + c;
                    if (nd <= k && nd < dist[v]) {
                        dist[v] = nd;
                        pq.push({nd, v});
                    }
                }
            }
            
            return dist[n-1] != LLONG_MAX;
        };
        
        // Binary search on threshold (candidate minimum edge cost)
        int lo = 0, hi = costs.size() - 1, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canAchieve(costs[mid])) {
                ans = costs[mid];
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return ans;
    }
};
