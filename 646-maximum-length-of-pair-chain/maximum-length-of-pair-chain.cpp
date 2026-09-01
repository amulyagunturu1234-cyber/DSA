class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });//srt by ending point
        int cnt=0;
        int lastRight=INT_MIN;
        for(int i=0;i<n;i++){
            if(pairs[i][0]>lastRight) {
                cnt++;
                lastRight=pairs[i][1];
            }
        }
        return cnt;
    }
};