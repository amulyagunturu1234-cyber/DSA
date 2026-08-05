class Solution {
    private:
    int f(int ind,vector<int> &nums,vector<int> &dp){
        if(ind>=nums.size()-1) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int minsteps=INT_MAX;
       for(int i=1;i<=nums[ind];i++){
         if(ind+i<nums.size()){
            int jump=f(ind+i,nums,dp);
            if(jump!=INT_MAX){
            minsteps=min(minsteps,1+jump);
            }
         }
       }
        return dp[ind]=minsteps;
    }
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
       return f(0,nums,dp);
    }
};