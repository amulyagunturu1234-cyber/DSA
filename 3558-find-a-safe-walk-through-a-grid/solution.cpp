class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0]; // cost to "enter" (0,0)
        
        deque<pair<int,int>> dq;
        dq.push_back({0, 0});
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                
                int weight = grid[nx][ny]; // 1 if unsafe, 0 if safe
                int newDist = dist[x][y] + weight;
                
                if (newDist < dist[nx][ny]) {
                    dist[nx][ny] = newDist;
                    if (weight == 0) {
                        dq.push_front({nx, ny});
                    } else {
                        dq.push_back({nx, ny});
                    }
                }
            }
        }
        
        // health must remain positive throughout, and end with >=1
        // health - dist[m-1][n-1] >= 1  =>  dist <= health - 1
        return dist[m-1][n-1] <= health - 1;
    }
};
