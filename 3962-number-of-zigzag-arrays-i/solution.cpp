class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const long long MOD = 1e9 + 7;
        int sz = r - l + 1;
        if (n == 1) return sz % MOD;

        vector<long long> up(sz), down(sz);
        for (int v = 0; v < sz; v++) {
            up[v] = v;
            down[v] = sz - 1 - v;
        }

        for (int i = 3; i <= n; i++) {
            // prefix sum of down, suffix sum of up
            vector<long long> pre(sz + 1, 0), suf(sz + 1, 0);
            for (int v = 0; v < sz; v++)
                pre[v + 1] = (pre[v] + down[v]) % MOD;
            for (int v = sz - 1; v >= 0; v--)
                suf[v] = (suf[v + 1] + up[v]) % MOD;

            for (int v = 0; v < sz; v++) {
                up[v]   = pre[v];       // sum of down[0..v-1]
                down[v] = suf[v + 1];   // sum of up[v+1..sz-1]
            }
        }

        long long ans = 0;
        for (int v = 0; v < sz; v++)
            ans = (ans + up[v] + down[v]) % MOD;
        return ans;
    }
};
