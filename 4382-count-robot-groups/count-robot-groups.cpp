class Solution {
public:
    int countGroups(vector<int>& p, vector<int>& s, int d) {
        vector<int> v;
        for(int i=0;i<p.size();i++)
            if(!i || (long long)p[i]-p[i-1]>d) v.push_back(s[i]);
            else v.back()=s[i];

        int ans=0,m=1e9;
        for(int i=v.size()-1;i>=0;i--)
            if(v[i]<=m) ans++,m=v[i];
        return ans;
    }
};
