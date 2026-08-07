class Solution {
    private:
    int f(int ind,int n,vector<int>& nums,vector<vector<int>> &dp){
        if(n==0) return 0;
        if(ind==0) return n;
        if(dp[ind][n]!=-1) return dp[ind][n];
        int tk=INT_MAX;
        if(nums[ind]<=n){
            tk=1+f(ind,n-nums[ind],nums,dp);
        }
        int nTk=0+f(ind-1,n,nums,dp);
        return dp[ind][n]=min(tk,nTk);
    }
public:
    int numSquares(int n) {
        vector<int>nums;
        for(int i=1;i*i<=n;i++){
            nums.push_back(i*i);
        }
        vector<vector<int>>dp(nums.size(),vector<int>(n+1,-1));
        return f(nums.size()-1,n,nums,dp);
    }
};