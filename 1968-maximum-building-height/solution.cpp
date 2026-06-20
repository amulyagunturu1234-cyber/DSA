class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        vector<vector<long long>> r;
        for (auto& res : restrictions)
            r.push_back({(long long)res[0], (long long)res[1]});

        // Building 1 must be height 0; building n can be at most n-1
        r.push_back({1, 0});
        r.push_back({(long long)n, (long long)n - 1});

        sort(r.begin(), r.end());

        // Merge duplicate ids (keep the tighter restriction)
        vector<vector<long long>> rr;
        for (auto& p : r) {
            if (!rr.empty() && rr.back()[0] == p[0])
                rr.back()[1] = min(rr.back()[1], p[1]);
            else
                rr.push_back(p);
        }
        r = rr;
        int m = r.size();

        // Forward pass: tighten using left neighbor
        for (int i = 1; i < m; i++) {
            long long dist = r[i][0] - r[i - 1][0];
            r[i][1] = min(r[i][1], r[i - 1][1] + dist);
        }

        // Backward pass: tighten using right neighbor
        for (int i = m - 2; i >= 0; i--) {
            long long dist = r[i + 1][0] - r[i][0];
            r[i][1] = min(r[i][1], r[i + 1][1] + dist);
        }

        long long ans = 0;
        for (int i = 0; i < m; i++)
            ans = max(ans, r[i][1]);

        // Check the highest achievable "peak" between every consecutive pair
        for (int i = 1; i < m; i++) {
            long long dist = r[i][0] - r[i - 1][0];
            long long peak = (r[i][1] + r[i - 1][1] + dist) / 2;
            ans = max(ans, peak);
        }

        return (int)ans;
    }
};
