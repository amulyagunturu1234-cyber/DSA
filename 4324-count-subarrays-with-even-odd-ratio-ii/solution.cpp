class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();

        vector<long long> p(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 == 0) {
                p[i + 1] = p[i] + b;
            } else {
                p[i + 1] = p[i] - a;
            }
        }

        vector<long long> vals = p;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = vals.size();
        vector<int> bit(m + 1, 0);

        long long ans = 0;
        for (int i = 0; i <= n; ++i) {
            int id = lower_bound(vals.begin(), vals.end(), p[i]) - vals.begin() + 1;

            int count = 0;
            for (int j = id - 1; j > 0; j -= j & -j) {
                count += bit[j];
            }

            ans += i - count;

            for (int j = id; j <= m; j += j & -j) {
                bit[j] += 1;
            }
        }

        return ans;
    }
};
