class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();

        vector<vector<long long>> R(m + 1, vector<long long>(n + 1, 0));
        vector<vector<long long>> D(m + 1, vector<long long>(n + 1, 0));

        // Start: treat as entering (0,0) with 1 way (counted once, via R)
        R[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long long r = R[i][j] % MOD;
                long long d = D[i][j] % MOD;

                if (grid[i][j] == 0) {
                    long long total = (r + d) % MOD;
                    if (i == m - 1 && j == n - 1) return (int)total;
                    // move right
                    if (j + 1 < n) R[i][j + 1] = (R[i][j + 1] + total) % MOD;
                    // move down
                    if (i + 1 < m) D[i + 1][j] = (D[i + 1][j] + total) % MOD;
                } else {
                    // mirror: entered moving right -> goes down
                    if (i + 1 < m) D[i + 1][j] = (D[i + 1][j] + r) % MOD;
                    // mirror: entered moving down -> goes right
                    if (j + 1 < n) R[i][j + 1] = (R[i][j + 1] + d) % MOD;
                }
            }
        }
        return 0; // last cell was a mirror
    }
};