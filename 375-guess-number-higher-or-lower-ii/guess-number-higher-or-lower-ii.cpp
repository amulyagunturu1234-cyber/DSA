class Solution {
    int f(int l, int r, vector<vector<int>>& dp) {

    if(l >= r)
        return 0;

    if(dp[l][r] != -1)
        return dp[l][r];

    int ans = INT_MAX;

    for(int k = l; k <= r; k++) {

        int cost = k + max(
            f(l, k-1, dp),
            f(k+1, r, dp)
        );

        ans = min(ans, cost);
    }

    return dp[l][r] = ans;
}
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    return f(1, n, dp);
    }
};