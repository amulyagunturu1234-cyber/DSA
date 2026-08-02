class Solution {
    private:
    int solve(int i,int j,vector<int>&nums,vector<vector<int>> &dp){
        if(i==j) return nums[i];
        if(dp[i][j]!=INT_MIN) return dp[i][j];//overlapping subacses
        int tkleft=nums[i]-solve(i+1,j,nums,dp);
        int tkright=nums[j]-solve(i,j-1,nums,dp);//instead of storing the both palyers sum seperately we are storing the difference a dry run helps
        return dp[i][j]=max(tkleft,tkright);
    }
public:
    bool stoneGame(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
        return solve(0,n-1,nums,dp)>=0;
    }
};
