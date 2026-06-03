class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        int ans = INT_MAX;

        // finish[i] = start[i] + duration[i]
        vector<int> lf(n), wf(m);
        for (int i = 0; i < n; i++) lf[i] = landStartTime[i] + landDuration[i];
        for (int j = 0; j < m; j++) wf[j] = waterStartTime[j] + waterDuration[j];

        sort(lf.begin(), lf.end());
        sort(wf.begin(), wf.end());

        // Case 1: Land first, then Water
        // For water ride j: finish = max(best_land_finish, waterStartTime[j]) + waterDuration[j]
        for (int j = 0; j < m; j++) {
            int ws = waterStartTime[j], wd = waterDuration[j];
            // Find min lf <= ws => finish = ws + wd
            auto it = lower_bound(lf.begin(), lf.end(), ws + 1); // first lf > ws
            if (it != lf.begin()) {
                ans = min(ans, ws + wd); // land finishes before water opens
            }
            if (it != lf.end()) {
                ans = min(ans, *it + wd); // smallest land finish > ws
            }
        }

        // Case 2: Water first, then Land
        for (int i = 0; i < n; i++) {
            int ls = landStartTime[i], ld = landDuration[i];
            auto it = lower_bound(wf.begin(), wf.end(), ls + 1);
            if (it != wf.begin()) {
                ans = min(ans, ls + ld);
            }
            if (it != wf.end()) {
                ans = min(ans, *it + ld);
            }
        }

        return ans;
    }
};
