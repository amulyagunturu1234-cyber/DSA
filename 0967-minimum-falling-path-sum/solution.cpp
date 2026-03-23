class Solution {
    int f(int i,int j,vector<vector<int>>& matrix,
            vector<vector<int>>& dp){
                int n=matrix.size();
                int m=matrix[0].size();
                //out of bound case
                int INF=1e9;
                if(j<0 ||j>=m) return INF;
                //base case
                if(i==0) return matrix[0][j];
                if(dp[i][j]!=INT_MIN) return dp[i][j];
                int ld=matrix[i][j]+f(i-1,j-1,matrix,dp);
                int bl=matrix[i][j]+f(i-1,j,matrix,dp);
                int rd=matrix[i][j]+f(i-1,j+1,matrix,dp);
                return dp[i][j]=min(ld,min(bl,rd));
            }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MIN));
        int ans = INT_MAX;
        for(int j = 0; j < m; j++)
        ans = min(ans, f(n-1, j, matrix, dp));
        return ans;
    }
};
