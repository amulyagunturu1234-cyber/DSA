class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int LOG = __lg(n) + 2;
        
        vector<vector<int>> smax(LOG, vector<int>(n)), smin(LOG, vector<int>(n));
        for (int i = 0; i < n; i++) smax[0][i] = smin[0][i] = nums[i];
        for (int j = 1; j < LOG; j++)
            for (int i = 0; i + (1 << j) <= n; i++) {
                smax[j][i] = max(smax[j-1][i], smax[j-1][i+(1<<(j-1))]);
                smin[j][i] = min(smin[j-1][i], smin[j-1][i+(1<<(j-1))]);
            }
        
        auto qmax = [&](int l, int r) {
            int t = __lg(r - l + 1);
            return max(smax[t][l], smax[t][r-(1<<t)+1]);
        };
        auto qmin = [&](int l, int r) {
            int t = __lg(r - l + 1);
            return min(smin[t][l], smin[t][r-(1<<t)+1]);
        };
        
        using T = tuple<long long, int, int>;
        priority_queue<T> pq;
        set<pair<int,int>> vis;
        
        auto push = [&](int l, int r) {
            if (l > r || vis.count({l, r})) return;
            vis.insert({l, r});
            pq.push({(long long)qmax(l,r) - qmin(l,r), l, r});
        };
        
        push(0, n - 1);
        
        long long ans = 0;
        for (int i = 0; i < k && !pq.empty(); i++) {
            auto [v, l, r] = pq.top(); pq.pop();
            ans += v;
            push(l + 1, r);
            push(l, r - 1);
        }
        return ans;
    }
};
