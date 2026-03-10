class Solution {
public:
    static const int MOD = 1e9 + 7; 
    int numberOfStableArrays(int zero, int one, int limit) {
         const long long MOD = 1e9 + 7;
        int Z = zero, O = one, L = limit;

        // dp[i][j][t]: # stable arrays with i zeros, j ones, ending with digit t
        // Transition:
        //   dp[i][j][0] = sum_{k=1}^{min(i,L)} dp[i-k][j][1]  + (j==0 && i<=L ? 1 : 0)
        //   dp[i][j][1] = sum_{k=1}^{min(j,L)} dp[i][j-k][0]  + (i==0 && j<=L ? 1 : 0)
        // Use prefix sums along each axis.

        vector<vector<array<long long,2>>> dp(Z+1, vector<array<long long,2>>(O+1, {0LL,0LL}));
        // row_prefix[i][j] = sum of dp[0..i][j][1]  (prefix over first index, fixed j)
        // col_prefix[i][j] = sum of dp[i][0..j][0]  (prefix over second index, fixed i)
        vector<vector<long long>> rowP(Z+2, vector<long long>(O+1, 0)); // rowP[i][j] = sum_{x=0}^{i} dp[x][j][1]
        vector<vector<long long>> colP(Z+1, vector<long long>(O+2, 0)); // colP[i][j] = sum_{y=0}^{j} dp[i][y][0]

        for(int i = 0; i <= Z; i++){
            for(int j = 0; j <= O; j++){
                if(i == 0 && j == 0){
                    rowP[0][0] = 0;
                    colP[0][0] = 0;
                    continue;
                }

                // Compute dp[i][j][0]: place 1..min(i,L) zeros, prev ends in 1
                if(i > 0){
                    int lo = i - L; // inclusive lower bound on i'
                    // sum rowP[i-1][j] - rowP[lo-1][j]
                    long long s = rowP[i-1][j];
                    if(lo - 1 >= 0) s = (s - rowP[lo-1][j] + MOD) % MOD;
                    // pure zero array: j==0 and i<=L
                    if(j == 0 && i <= L) s = (s + 1) % MOD;
                    dp[i][j][0] = s;
                }

                // Compute dp[i][j][1]: place 1..min(j,L) ones, prev ends in 0
                if(j > 0){
                    int lo = j - L;
                    long long s = colP[i][j-1];
                    if(lo - 1 >= 0) s = (s - colP[i][lo-1] + MOD) % MOD;
                    if(i == 0 && j <= L) s = (s + 1) % MOD;
                    dp[i][j][1] = s;
                }

                // Update prefix sums
                rowP[i][j] = ((i > 0 ? rowP[i-1][j] : 0) + dp[i][j][1]) % MOD;
                colP[i][j] = ((j > 0 ? colP[i][j-1] : 0) + dp[i][j][0]) % MOD;
            }
        }

        return (dp[Z][O][0] + dp[Z][O][1]) % MOD;
    }
};
