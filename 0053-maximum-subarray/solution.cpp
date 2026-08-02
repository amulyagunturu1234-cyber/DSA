class Solution {
    private:
    int f(int ind,vector<int> &nums,vector<int> &dp){
        if(ind==0) return nums[0];
        if(dp[ind]!=INT_MIN) return dp[ind];
        int take=nums[ind]+max(0,f(ind-1,nums,dp));
        return dp[ind]=take;
    }
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,INT_MIN);
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,f(i,nums,dp));
        }
        return ans;
    }
};
