class Solution {
    int f(int ind,string &s,vector<int> &dp){
        if(ind==s.size()) return 1;
        if(s[ind]=='0') return 0;
        if(dp[ind]!=-1) return dp[ind];
        int ans=f(ind+1,s,dp);
        if(ind+1<s.size() && (s[ind]=='1' || (s[ind]=='2' && s[ind+1]<='6'))) ans+=f(ind+2,s,dp);
        return dp[ind]=ans;

    }
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return f(0,s,dp);
    }
};
