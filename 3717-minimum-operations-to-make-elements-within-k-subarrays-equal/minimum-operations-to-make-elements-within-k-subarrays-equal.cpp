class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        const long long INF = LLONG_MAX / 4;

        // ---- Step 1: cost of each window via sliding median ----
        multiset<int> lo, hi;
        long long sumLo = 0, sumHi = 0;

        auto rebalance = [&]() {
            int target = (lo.size() + hi.size() + 1) / 2;
            while ((int)lo.size() > target) {
                auto it = prev(lo.end());
                sumLo -= *it; sumHi += *it;
                hi.insert(*it); lo.erase(it);
            }
            while ((int)lo.size() < target) {
                auto it = hi.begin();
                sumHi -= *it; sumLo += *it;
                lo.insert(*it); hi.erase(it);
            }
        };
        auto add = [&](int v) {
            if (lo.empty() || v <= *lo.rbegin()) { lo.insert(v); sumLo += v; }
            else { hi.insert(v); sumHi += v; }
            rebalance();
        };
        auto remove = [&](int v) {
            auto it = lo.find(v);
            if (it != lo.end()) { lo.erase(it); sumLo -= v; }
            else { hi.erase(hi.find(v)); sumHi -= v; }
            rebalance();
        };

        vector<long long> cost(n - x + 1);
        for (int i = 0; i < n; i++) {
            add(nums[i]);
            if (i >= x) remove(nums[i - x]);
            if (i >= x - 1) {
                long long med = *lo.rbegin();
                cost[i - x + 1] = med * (long long)lo.size() - sumLo
                                + sumHi - med * (long long)hi.size();
            }
        }

        // ---- Step 2: DP ----
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF));
        for (int i = 0; i <= n; i++) dp[0][i] = 0;

        for (int j = 1; j <= k; j++) {
            for (int i = x; i <= n; i++) {
                dp[j][i] = dp[j][i - 1];
                if (dp[j - 1][i - x] < INF)
                    dp[j][i] = min(dp[j][i], dp[j - 1][i - x] + cost[i - x]);
            }
        }
        return dp[k][n];
    }
};