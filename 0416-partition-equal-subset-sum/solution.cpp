class Solution {
    bool f(int ind,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(target==0) return true;
        if(ind==0) return (nums[ind]==target);
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool notPick=f(ind-1,target,nums,dp);
        bool pick=false;
        if(target>=nums[ind]) pick=f(ind-1,target-nums[ind],nums,dp);
        return dp[ind][target]=pick|notPick;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totSum=0;
        for(int i=0;i<n;i++){
            totSum+=nums[i];
        }
        if(totSum%2!=0)return false;
        int k=totSum/2;
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return f(n-1,k,nums,dp);
    }
};
