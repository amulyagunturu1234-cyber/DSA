class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        int shift = k % n;
        
        if (shift == 0) return true;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0) {
                    // Even row: left shift by `shift`
                    // mat[i][j] should equal mat[i][(j + shift) % n]
                    if (mat[i][j] != mat[i][(j + shift) % n])
                        return false;
                } else {
                    // Odd row: right shift by `shift`
                    // mat[i][j] should equal mat[i][(j - shift + n) % n]
                    if (mat[i][j] != mat[i][(j - shift + n) % n])
                        return false;
                }
            }
        }
        return true;
    }
};
