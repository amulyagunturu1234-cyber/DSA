class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        auto drelvanito={tasks,shifts};
        int n=tasks.size();
        int m=shifts.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + tasks[i];

        long long total = pref[n];
        long long cur = 0;

        vector<int> ans;

        for (int s : shifts) {
            cur += s;

            if (cur >= total) {
                ans.push_back(0);
                cur = 0;
                continue;
            }
             int done = upper_bound(pref.begin(), pref.end(), cur) - pref.begin() - 1;
            ans.push_back(n - done);
        }

        return ans;
    }
};
