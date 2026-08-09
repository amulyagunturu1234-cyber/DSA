class Solution {
    private:
    int f(int ind,int M,vector<int> &piles,
    vector<vector<int>> &dp){
        int n=piles.size();
        if(ind>=n) return 0;
         if (M > n)
            M = n;
        if(dp[ind][M]!=-1) return dp[ind][M];
        int ans=0;
        for (int X = 1; X <= 2 * M && ind + X <= n; X++) {
            int taken = 0;
            for (int j = ind; j < ind + X; j++) {
                taken += piles[j];
            }
            int newM = max(M, X);
            int remaining = 0;
            for (int j = ind + X; j < n; j++) {
                remaining += piles[j];
            }
             int opponent = f(ind + X, newM, piles, dp);
            int current = taken + remaining - opponent;
            ans = max(ans, current);
        }
        return dp[ind][M] = ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(2*n+1,-1));
        return f(0,1,piles,dp);
    }
};