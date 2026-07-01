class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int,int>> q;
        
        // Multi-source BFS from all thieves
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        // If start or end cell has a thief, safeness factor is 0
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;
        
        // Max-priority-queue Dijkstra-like approach to maximize minimum dist along path
        vector<vector<int>> safeness(n, vector<int>(n, -1));
        priority_queue<pair<int,int>> pq; // {safeness value, encoded cell}
        
        safeness[0][0] = dist[0][0];
        pq.push({safeness[0][0], 0 * n + 0});
        
        while (!pq.empty()) {
            auto [sf, code] = pq.top(); pq.pop();
            int x = code / n, y = code % n;
            
            if (sf < safeness[x][y]) continue; // outdated entry
            
            if (x == n - 1 && y == n - 1) {
                return sf;
            }
            
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    int newSafeness = min(sf, dist[nx][ny]);
                    if (newSafeness > safeness[nx][ny]) {
                        safeness[nx][ny] = newSafeness;
                        pq.push({newSafeness, nx * n + ny});
                    }
                }
            }
        }
        
        return safeness[n-1][n-1];
    }
};
