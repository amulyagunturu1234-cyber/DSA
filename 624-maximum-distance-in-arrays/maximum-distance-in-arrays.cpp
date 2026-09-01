class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m=arrays.size();
        //find max of all arrays and min of all arrays and then use min of all the minimums -max of al maxms if they beong to diff arrays or else take econd min or second maxm
        int globalMin = arrays[0][0];
        int globalMax = arrays[0].back();

        int ans = 0;
        for(int i=1;i<m;i++){
            int currentMin = arrays[i][0];
            int currentMax = arrays[i].back();

            // Current array with previous arrays
            ans = max(ans, currentMax - globalMin);
            ans = max(ans, globalMax - currentMin);

            // Update global min and max
            globalMin = min(globalMin, currentMin);
            globalMax = max(globalMax, currentMax);
        }
        return ans;
    }
};