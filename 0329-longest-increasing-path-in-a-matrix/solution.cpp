class Solution {
    private:
   int dfs(vector<vector<int>> &matrix,vector<vector<int>> &dp,int row,int col,
      int delrow[],int delcol[],int n,int m){
        if(dp[row][col]!=-1) return dp[row][col];
                            int ans=1;
        for(int i=0;i<4;i++){
                    int nrow=row+delrow[i];
                    int ncol=col+delcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                matrix[nrow][ncol]>matrix[row][col]){
                    ans=max(ans,1+dfs(matrix,dp,nrow,ncol,delrow,delcol,n,m));
        }
    }
            return dp[row][col]=ans; 
   }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res=max(res,dfs(matrix,dp,i,j,delrow,delcol,n,m));
            }
        }
        return res;
    }
};
