class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int total = n * m;
        const int MOD = 12345;
        
        vector<vector<int>> p(n, vector<int>(m, 1));
        
        // Flatten approach: prefix and suffix products
        // prefix[k] = product of all elements before index k (in row-major order)
        // suffix[k] = product of all elements after index k
        
        vector<long long> prefix(total + 1, 1), suffix(total + 1, 1);
        
        // Build prefix products
        for (int k = 0; k < total; k++) {
            int i = k / m, j = k % m;
            prefix[k + 1] = (prefix[k] * (grid[i][j] % MOD)) % MOD;
        }
        
        // Build suffix products
        for (int k = total - 1; k >= 0; k--) {
            int i = k / m, j = k % m;
            suffix[k] = (suffix[k + 1] * (grid[i][j] % MOD)) % MOD;
        }
        
        // For each cell k, p[i][j] = prefix[k] * suffix[k+1]
        for (int k = 0; k < total; k++) {
            int i = k / m, j = k % m;
            p[i][j] = (prefix[k] * suffix[k + 1]) % MOD;
        }
        
        return p;
    }
};
