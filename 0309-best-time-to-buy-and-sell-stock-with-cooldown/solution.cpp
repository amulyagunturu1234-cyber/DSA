class Solution {
    int f(int ind,int buy,vector<int>& prices,vector<vector<int>>& dp){
        int n=prices.size();
        if(ind>=n) return 0;
        int profit;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        if(buy){
           dp[ind][buy]=profit=max((-prices[ind]+f(ind+1,0,prices,dp)),(0+f(ind+1,1,prices,dp)));
        }
        else dp[ind][buy]=profit=max((prices[ind]+f(ind+2,1,prices,dp)),(0+f(ind+1,0,prices,dp)));
        return dp[ind][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};
