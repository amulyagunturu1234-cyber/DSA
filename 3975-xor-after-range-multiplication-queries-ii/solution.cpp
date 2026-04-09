#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        int B = max(1, (int)sqrt(n)); // block size ~ sqrt(n)

        // For large k (k > B): apply directly to nums
        // For small k (k <= B): lazy accumulation
        // lazy[k][r] = product of all multipliers applied at step k,
        // accumulated as a "difference array" per (k, offset)
        // We store: for each k in [1..B], for each offset in [0..k-1],
        // a prefix-product array over positions in that residue class.

        // To avoid O(n*B) memory upfront, use map or flat arrays.
        // We'll use: mult[k] = vector of size n, where mult[k][i] = product
        // of all v's applied at index i via queries with step k.
        // But that's still O(n*B). Instead, use difference trick:
        // For each query (l, r, k, v) with k <= B:
        //   diff[k][l/k * k + offset] ... this is complex.
        // 
        // Simpler: For k <= B, store per (k) a "lazy range multiply" array
        // that we collapse at the end.

        // --- Approach: segment-based lazy for small k ---
        // For each small k, maintain lazy[k] as a "step-k range multiply" accumulator.
        // At the end, for each element i, compute product of all lazy[k][i % k ... ] contributions.

        // Use: for small k, store vector<long long> lazy_k[k] of size ceil(n/k).
        // lazy_k[k][j] means "multiply all elements at positions j*k + 0..k-1 of this group".
        // Use a prefix product difference array: mult_diff[k][j] *= v means "from group j onwards".

        // Final implementation: difference array per small k
        // lazy[k] is indexed by "position in the sequence for step k starting at offset 0..k-1"
        // i.e., for index i with step k, it belongs to group: i (within step-k arithmetic sequence from i%k)

        // Store mult[k][i] = product of all multipliers that hit index i via step-k queries
        // Use difference arrays: for query (l,r,k,v): mult_diff[k][l] *= v, undo after r+k

        // We'll use flat arrays with care.
        
        // For small k: diff[k] has size n+1
        // diff[k][i] *= v, diff[k][next_after_r] *= modinv(v)
        // Then prefix product over step k gives per-element multiplier.

        // Precompute modular inverse via Fermat's little theorem
        auto modinv = [&](long long a) -> long long {
            long long res = 1, exp = MOD - 2, base = a % MOD;
            while (exp > 0) {
                if (exp & 1) res = res * base % MOD;
                base = base * base % MOD;
                exp >>= 1;
            }
            return res;
        };

        // diff[k][i]: for step k, multiplier applied starting at i (step k apart)
        // size: B+1 vectors each of size n+1
        vector<vector<long long>> diff(B + 1, vector<long long>(n + 1, 1));

        // Process queries
        for (auto& qr : queries) {
            int l = qr[0], r = qr[1], k = qr[2];
            long long v = qr[3];

            if (k > B) {
                // Large k: directly multiply affected elements
                for (int idx = l; idx <= r; idx += k) {
                    nums[idx] = (long long)nums[idx] * v % MOD;
                }
            } else {
                // Small k: use difference array for step k
                // The sequence l, l+k, l+2k, ..., <=r
                // In diff[k], apply v at position l, and apply inv(v) at first position > r in this sequence
                diff[k][l] = diff[k][l] * v % MOD;
                // next position after r in sequence starting l with step k:
                // it's l + ceil((r - l)/k + 1) * k
                long long next;
                if (r >= l) {
                    next = (long long)l + ((long long)(r - l) / k + 1) * k;
                } else {
                    next = l;
                }
                if (next <= n) {
                    diff[k][next] = diff[k][next] * modinv(v) % MOD;
                }
            }
        }

        // Now compute final value for each element
        // For small k: running product per residue class
        // For each k in [1..B], scan indices 0..n-1 in steps of 1,
        // maintaining running product per residue mod k.
        // Actually: diff[k] is indexed by absolute position i,
        // but the step-k queries only hit i where i ≡ l (mod k) for various l.
        // The difference array works as follows:
        // For step k, the "effective multiplier at index i" =
        //   product of diff[k][j] for all j <= i where j ≡ i (mod k)

        // So for each k, for each offset o in [0, k-1],
        // scan positions o, o+k, o+2k, ... maintaining prefix product.

        vector<long long> finalMult(n, 1);
        for (int k = 1; k <= B; k++) {
            for (int o = 0; o < k && o < n; o++) {
                long long cur = 1;
                for (int i = o; i < n; i += k) {
                    cur = cur * diff[k][i] % MOD;
                    finalMult[i] = finalMult[i] * cur % MOD;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long val = (long long)nums[i] * finalMult[i] % MOD;
            ans ^= (int)val;
        }
        return ans;
    }
};
