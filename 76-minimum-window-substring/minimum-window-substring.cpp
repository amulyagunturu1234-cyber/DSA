class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        int l=0,r=0;
        int hash[256]={0};
        int minLen=1e9;
        int sInd=-1;
        int cnt=0;
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }
        while(r<n){
            if(hash[s[r]]>0) cnt=cnt+1;
            hash[s[r]]--;
            while(cnt==m){
                if(r-l+1<minLen){
                    minLen=r-l+1;
                    sInd=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0) cnt=cnt-1;
                l++;
            }
            r=r+1;
        }
        return sInd==-1?"":s.substr(sInd,minLen);
        }
};