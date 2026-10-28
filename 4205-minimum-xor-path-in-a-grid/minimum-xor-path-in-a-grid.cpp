class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int K = 1024; // values are < 1024, so XORs stay < 1024
        vector<vector<char>> dp(n, vector<char>(K, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int v = grid[i][j];
                vector<char> nxt(K, 0);
                if (i == 0 && j == 0) {
                    nxt[v] = 1;
                } else {
                    for (int x = 0; x < K; x++) {
                        bool ok = dp[j][x];                // from above (old row value)
                        if (j > 0 && dp[j - 1][x]) ok = true; // from left (already updated)
                        if (ok) nxt[x ^ v] = 1;
                    }
                }
                dp[j] = move(nxt);
            }
        }

        for (int x = 0; x < K; x++)
            if (dp[n - 1][x]) return x;
        return -1;
    }
};