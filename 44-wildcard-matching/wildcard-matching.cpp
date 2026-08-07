class Solution {
    bool f(int i ,int j,string &s,string &p,vector<vector<int>>&dp){
        if(i<0 && j<0) return true;//both strings xhausted
        if(j<0 && i>=0) return false;//only 1stnd string exhausted
        if(j>=0 && i<0){ 
            for(int k=0;k<=j;k++){
                if(p[k]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?') return dp[i][j]=f(i-1,j-1,s,p,dp);
        else if(p[j]=='*') return dp[i][j]=(f(i-1,j,s,p,dp) || f(i,j-1,s,p,dp));
        return dp[i][j]=false;
    }
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,p,dp);
    }
};