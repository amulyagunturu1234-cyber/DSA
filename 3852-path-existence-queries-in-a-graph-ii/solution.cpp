class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });
        
        vector<int> sortedNums(n);
        for (int i = 0; i < n; i++) sortedNums[i] = nums[idx[i]];
        
        // component id: positions connected if consecutive diff <= maxDiff
        vector<int> comp(n);
        comp[0] = 0;
        for (int i = 1; i < n; i++) {
            comp[i] = comp[i-1] + (sortedNums[i] - sortedNums[i-1] > maxDiff ? 1 : 0);
        }
        
        // map original node -> position in sorted order
        vector<int> pos(n);
        for (int i = 0; i < n; i++) pos[idx[i]] = i;
        
        // nxt[i] = farthest position reachable using greedy max jump starting from i,
        // built correctly using two-pointer over the *reachability window* (like jump game)
        vector<int> nxt(n);
        {
            int far = 0;
            for (int i = 0; i < n; i++) {
                if (far < i) far = i;
                // extend as long as adding next index keeps window within maxDiff of sortedNums[i]... 
                // Actually correct greedy: farthest index j such that sortedNums[j]-sortedNums[i] <= maxDiff
                int j = far;
                while (j + 1 < n && sortedNums[j+1] - sortedNums[i] <= maxDiff) j++;
                far = j;
                nxt[i] = far;
            }
        }
        
        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        LOG++;
        
        vector<vector<int>> up(LOG, vector<int>(n));
        up[0] = nxt;
        for (int k = 1; k < LOG; k++)
            for (int i = 0; i < n; i++)
                up[k][i] = up[k-1][up[k-1][i]];
        
        int m = queries.size();
        vector<int> ans(m, -1);
        
        for (int q = 0; q < m; q++) {
            int u = queries[q][0], v = queries[q][1];
            if (u == v) { ans[q] = 0; continue; }
            int pu = pos[u], pv = pos[v];
            if (pu > pv) swap(pu, pv);
            if (comp[pu] != comp[pv]) { ans[q] = -1; continue; }
            
            int cur = pu;
            long long steps = 0;
            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < pv) {
                    cur = up[k][cur];
                    steps += (1LL << k);
                }
            }
            steps += 1;
            ans[q] = (int)steps;
        }
        
        return ans;
    }
};
