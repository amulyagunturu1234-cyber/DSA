class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string t=s;
        reverse(t.begin(),t.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        //1-based indexing
        //since we are initialsing evveryhing by 0 no problem
        int ans=0;
        int maxi=0;
        int maxj=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    if(dp[i][j]>ans && (i - dp[i][j]) == (n - j)){
                    ans=dp[i][j];
                    maxi=i;
                    maxj=j;
                    }
                }
                else dp[i][j]=0;
            }
        }
        //dp is prepared
       int i=maxi;
       int j=maxj;
       int len=ans;
       int ind=len-1;
       string p(len,'$');
    while(i>0 && j>0 && dp[i][j]>0){
            p[ind]=s[i-1];
            i--;
            j--;
            ind--;
        }
        return p;
    }
};
