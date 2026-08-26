class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int ans=0;
        int prevEnd=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<prevEnd){ ans++;
            prevEnd=min(prevEnd,intervals[i][1]);
            }
            else prevEnd=intervals[i][1];
        }
        return ans;
    }
};