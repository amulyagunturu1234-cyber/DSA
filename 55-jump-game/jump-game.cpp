class Solution {
    private:
    int f(int ind,vector<int> &nums,vector<int> &dp){
        if(ind>=nums.size()-1) return true;
       if(dp[ind]!=-1) return dp[ind];
       for(int i=1;i<=nums[ind];i++){
         if(ind+i<nums.size()){
            if(f(ind+i,nums,dp)){
              return dp[ind]=true;;
            }
         }
       }
        return dp[ind]=false;
    }
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
       return f(0,nums,dp);
    }
};