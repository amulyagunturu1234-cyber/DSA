class Solution {
    const int MOD = 1e9 + 7;
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        // dp[i][j] = {max_product, min_product} reaching cell (i,j)
        vector<vector<pair<long long,long long>>> dp(n, vector<pair<long long,long long>>(m));
        
        // Base case: top-left
        dp[0][0] = {grid[0][0], grid[0][0]};
        
        // Base case: first row (only one path — all from left)
        for (int j = 1; j < m; j++) {
            dp[0][j] = {dp[0][j-1].first * grid[0][j], 
                        dp[0][j-1].second * grid[0][j]};
        }
        
        // Base case: first column (only one path — all from top)
        for (int i = 1; i < n; i++) {
            dp[i][0] = {dp[i-1][0].first * grid[i][0], 
                        dp[i-1][0].second * grid[i][0]};
        }
        
        // Fill rest
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                long long g = grid[i][j];
                // All 4 candidates: multiply current cell with max/min from top and left
                long long a = dp[i-1][j].first * g;
                long long b = dp[i-1][j].second * g;
                long long c = dp[i][j-1].first * g;
                long long d = dp[i][j-1].second * g;
                dp[i][j] = {max({a,b,c,d}), min({a,b,c,d})};
            }
        }
        
        long long ans = dp[n-1][m-1].first;
        return ans < 0 ? -1 : ans % MOD;
    }
};
