class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Directions: North, East, South, West (clockwise)
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        // Store obstacles in a hash set for O(1) lookup
        set<pair<int,int>> obstacleSet;
        for (auto& obs : obstacles) {
            obstacleSet.insert({obs[0], obs[1]});
        }
        
        int x = 0, y = 0;
        int dir = 0; // Start facing North (index 0)
        int maxDist = 0;
        
        for (int cmd : commands) {
            if (cmd == -2) {
                // Turn left 90 degrees
                dir = (dir + 3) % 4;
            } else if (cmd == -1) {
                // Turn right 90 degrees
                dir = (dir + 1) % 4;
            } else {
                // Move forward k steps
                for (int step = 0; step < cmd; step++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    
                    // Only move if no obstacle
                    if (obstacleSet.find({nx, ny}) == obstacleSet.end()) {
                        x = nx;
                        y = ny;
                        maxDist = max(maxDist, x*x + y*y);
                    } else {
                        break; // Stop moving in this direction
                    }
                }
            }
        }
        
        return maxDist;
    }
};
