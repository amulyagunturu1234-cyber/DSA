class Solution {
    private:
    bool f(int stones,vector<int> &dp){
        if(stones==0) return false;
        //take only if its a perfect number;
        if(dp[stones]!=-1) return dp[stones];
         for (int i = 1; i * i <= stones; i++) {
            int square = i * i;
            if (!f(stones - square, dp))
                return dp[stones] = true;
        }
        return dp[stones] = false;
    }
public:
    bool winnerSquareGame(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};