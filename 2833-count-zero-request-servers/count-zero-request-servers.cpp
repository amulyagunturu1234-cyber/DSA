class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        // sort logs by time
        sort(logs.begin(), logs.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        // sort queries, keep original indices
        int m = queries.size();
        vector<pair<int,int>> qs(m);
        for (int i = 0; i < m; i++) qs[i] = {queries[i], i};
        sort(qs.begin(), qs.end());

        vector<int> cnt(n + 1, 0);
        vector<int> ans(m);
        int active = 0;      // servers with at least one request in window
        int l = 0, r = 0;    // l: next log to remove, r: next log to add
        int sz = logs.size();

        for (auto& [q, idx] : qs) {
            // add logs with time <= q
            while (r < sz && logs[r][1] <= q) {
                if (cnt[logs[r][0]]++ == 0) active++;
                r++;
            }
            // remove logs with time < q - x
            while (l < r && logs[l][1] < q - x) {
                if (--cnt[logs[l][0]] == 0) active--;
                l++;
            }
            ans[idx] = n - active;
        }
        return ans;
    }
};