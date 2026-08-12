class Solution {
    bool f(int ind,string &s,vector<string>&  wordDict,vector<int> &dp){
        //ind is pointing to the characters belonging to s 
        if(ind==s.length()) return true;
        if(dp[ind]!=-1)return dp[ind];
        for(string word:wordDict){
            int len=word.length();
            if(ind + len <= s.length() && s.substr(ind,len)==word){
                if(f(ind + len, s, wordDict, dp))
                    return dp[ind] = true;
            }
        }
        return dp[ind]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return f(0,s,wordDict,dp);
    }
};