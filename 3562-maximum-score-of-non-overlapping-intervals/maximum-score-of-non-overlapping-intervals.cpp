class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            if (intervals[a][1] != intervals[b][1]) return intervals[a][1] < intervals[b][1];
            return a < b;
        });

        vector<long long> R(n), L(n), W(n);
        vector<int> idx(n);
        for (int i = 0; i < n; i++) {
            L[i] = intervals[order[i]][0];
            R[i] = intervals[order[i]][1];
            W[i] = intervals[order[i]][2];
            idx[i] = order[i];
        }

        const int K = 4;
        using State = pair<long long, vector<int>>; // {score, sorted chosen indices}
        vector<vector<State>> dp(K + 1, vector<State>(n + 1));

        for (int k = 0; k <= K; k++) dp[k][0] = {0LL, {}};
        for (int i = 0; i <= n; i++) dp[0][i] = {0LL, {}};

        auto better = [](const State& a, const State& b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second; // lexicographic, shorter prefix wins ties
        };

        for (int i = 1; i <= n; i++) {
            int predCount = lower_bound(R.begin(), R.end(), L[i - 1]) - R.begin();
            for (int k = 1; k <= K; k++) {
                State best = dp[k][i - 1]; // skip current interval
                State take = dp[k - 1][predCount];
                take.first += W[i - 1];
                take.second.push_back(idx[i - 1]);
                sort(take.second.begin(), take.second.end());
                if (better(take, best)) best = take;
                dp[k][i] = best;
            }
        }

        return dp[K][n].second;
    }
};