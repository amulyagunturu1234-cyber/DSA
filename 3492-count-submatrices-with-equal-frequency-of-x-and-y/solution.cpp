class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int result = 0;
        
        // prefix[i][j] = {count of X, count of Y} in submatrix (0,0) to (i,j)
        vector<vector<pair<int,int>>> prefix(m, vector<pair<int,int>>(n, {0, 0}));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x = (grid[i][j] == 'X') ? 1 : 0;
                int y = (grid[i][j] == 'Y') ? 1 : 0;
                
                // 2D prefix sum
                if (i > 0) {
                    x += prefix[i-1][j].first;
                    y += prefix[i-1][j].second;
                }
                if (j > 0) {
                    x += prefix[i][j-1].first;
                    y += prefix[i][j-1].second;
                }
                if (i > 0 && j > 0) {
                    x -= prefix[i-1][j-1].first;
                    y -= prefix[i-1][j-1].second;
                }
                
                prefix[i][j] = {x, y};
                
                // Valid submatrix: equal X and Y, at least one X
                if (x == y && x > 0) {
                    result++;
                }
            }
        }
        
        return result;
    }
};
