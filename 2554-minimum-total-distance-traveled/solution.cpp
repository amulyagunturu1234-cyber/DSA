class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        // Flatten factories based on their limits
        vector<int> f;
        for (auto& fc : factory)
            for (int k = 0; k < fc[1]; k++)
                f.push_back(fc[0]);
        
        int n = robot.size(), m = f.size();
        const long long INF = 1e18;
        
        // dp[i][j]: min cost to assign robots[0..i-1] to some subset of slots[0..j-1]
        // Recurrence:
        //   dp[i][j] = min(dp[i][j-1],                           // don't use slot j
        //                  dp[i-1][j-1] + |robot[i-1] - f[j-1]|) // assign robot i to slot j
        // Base: dp[0][j] = 0 for all j (no robots = no cost)
        //       dp[i][0] = INF for i>0
        
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, INF));
        for (int j = 0; j <= m; j++) dp[0][j] = 0;
        
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= m; j++) {
                dp[i][j] = dp[i][j-1]; // skip slot j
                if (dp[i-1][j-1] != INF)
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + abs((long long)robot[i-1] - f[j-1]));
            }
        }
        
        return dp[n][m];
    }
};
