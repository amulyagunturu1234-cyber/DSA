class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int n = nums.size();

        vector<long long> sum(4 * n), sq(4 * n), lazy(4 * n);
        unordered_map<int, int> last;
        long long ans = 0;

        auto push = [&](int node, int l, int r) {
            if (lazy[node] == 0) return;

            long long v = lazy[node];
            int len = r - l + 1;

            sq[node] = (sq[node] + 2 * v % mod * sum[node] % mod
                        + v * v % mod * len) % mod;
            sum[node] = (sum[node] + v * len) % mod;

            if (l != r) {
                lazy[node * 2] = (lazy[node * 2] + v) % mod;
                lazy[node * 2 + 1] = (lazy[node * 2 + 1] + v) % mod;
            }
            lazy[node] = 0;
        };

        auto update = [&](auto&& self, int node, int l, int r,
                          int ql, int qr) -> void {
            push(node, l, r);
            if (r < ql || l > qr) return;

            if (ql <= l && r <= qr) {
                lazy[node] = (lazy[node] + 1) % mod;
                push(node, l, r);
                return;
            }

            int mid = (l + r) / 2;
            self(self, node * 2, l, mid, ql, qr);
            self(self, node * 2 + 1, mid + 1, r, ql, qr);

            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % mod;
            sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % mod;
        };

        for (int i = 0; i < n; i++) {
            int prev = -1;
            if (last.count(nums[i])) prev = last[nums[i]];

            update(update, 1, 0, n - 1, prev + 1, i);
            last[nums[i]] = i;

            ans = (ans + sq[1]) % mod;
        }

        return ans;
    }
};