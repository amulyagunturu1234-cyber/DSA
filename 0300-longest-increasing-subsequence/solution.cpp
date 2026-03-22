class Solution {
    private:
    int f(int ind,vector<int>& nums,vector<int>& dp){
        if(ind<0) return 0;
        if(dp[ind]!=-1)return dp[ind];
        int best=1;
        for(int j=ind+1;j<nums.size();j++){
            if(nums[j]>nums[ind]){
            best= max(best,1+f(j,nums,dp));
            }
        }
        return dp[ind]=best;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,f(i,nums,dp));
        }
        return ans;
    }
};
