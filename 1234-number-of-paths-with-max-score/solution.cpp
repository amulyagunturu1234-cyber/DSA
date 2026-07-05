class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;
        vector<vector<long long>> dp(n, vector<long long>(n, -1));
        vector<vector<long long>> cnt(n, vector<long long>(n, 0));
        
        board[0][0] = '0';
        board[n-1][n-1] = '0';
        
        dp[n-1][n-1] = 0;
        cnt[n-1][n-1] = 1;
        
        int dirs[3][2] = {{-1,0},{0,-1},{-1,-1}};
        
        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (i == n-1 && j == n-1) continue;
                if (board[i][j] == 'X') continue;
                
                long long best = -1, ways = 0;
                for (auto& d : dirs) {
                    int ni = i - d[0], nj = j - d[1];
                    // careful: we need i+1, j (down), i, j+1 (right), i+1,j+1 (down-right) as predecessors
                }
                // predecessors are (i+1,j), (i,j+1), (i+1,j+1)
                int pi[3] = {i+1, i, i+1};
                int pj[3] = {j, j+1, j+1};
                for (int k = 0; k < 3; k++) {
                    int ni = pi[k], nj = pj[k];
                    if (ni < n && nj < n && dp[ni][nj] != -1) {
                        if (dp[ni][nj] > best) {
                            best = dp[ni][nj];
                            ways = cnt[ni][nj];
                        } else if (dp[ni][nj] == best) {
                            ways = (ways + cnt[ni][nj]) % MOD;
                        }
                    }
                }
                
                if (best != -1) {
                    dp[i][j] = best + (board[i][j] - '0');
                    cnt[i][j] = ways;
                }
            }
        }
        
        if (dp[0][0] == -1) return {0, 0};
        return {(int)dp[0][0], (int)cnt[0][0]};
    }
};
