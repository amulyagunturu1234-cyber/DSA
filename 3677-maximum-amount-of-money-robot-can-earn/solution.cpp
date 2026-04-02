class Solution {
    int dp[801][801][3];
    
    int f(int i, int j, int k, vector<vector<int>>& coins) {
        // k = number of robbers neutralized so far (0, 1, or 2)
        if (i < 0 || j < 0) return INT_MIN / 2;
        if (i == 0 && j == 0) {
            // At starting cell: neutralize if negative and we have budget
            if (coins[0][0] < 0 && k > 0) return 0; // neutralize it
            return coins[0][0];
        }
        if (dp[i][j][k] != INT_MIN) return dp[i][j][k];
        
        int val = coins[i][j];
        
        if (val >= 0) {
            // Positive cell: always take it
            int left = f(i, j - 1, k, coins);
            int up   = f(i - 1, j, k, coins);
            return dp[i][j][k] = val + max(left, up);
        } else {
            // Negative cell: option 1 - pay the penalty
            int left = f(i, j - 1, k, coins);
            int up   = f(i - 1, j, k, coins);
            int take = val + max(left, up);
            
            // Option 2 - neutralize (if we still have neutralizations left)
            int neutralize = INT_MIN / 2;
            if (k > 0) {
                int left2 = f(i, j - 1, k - 1, coins);
                int up2   = f(i - 1, j, k - 1, coins);
                neutralize = 0 + max(left2, up2); // cell becomes 0
            }
            
            return dp[i][j][k] = max(take, neutralize);
        }
    }
    
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        // Fill dp with INT_MIN as "unvisited" sentinel
        for (auto& a : dp)
            for (auto& b : a)
                fill(b, b + 3, INT_MIN);
        
        // Start from bottom-right, k=2 (2 neutralizations available)
        return f(m - 1, n - 1, 2, coins);
    }
};
