class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int rows = m - k + 1, cols = n - k + 1;
        vector<vector<int>> ans(rows, vector<int>(cols, 0));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Collect all elements in k x k submatrix
                vector<int> vals;
                vals.reserve(k * k);
                for (int r = i; r < i + k; r++)
                    for (int c = j; c < j + k; c++)
                        vals.push_back(grid[r][c]);
                
                sort(vals.begin(), vals.end());
                
                int minDiff = INT_MAX;
                for (int x = 1; x < (int)vals.size(); x++) {
                    if (vals[x] != vals[x-1]) {
                        minDiff = min(minDiff, vals[x] - vals[x-1]);
                    }
                }
                
                ans[i][j] = (minDiff == INT_MAX) ? 0 : minDiff;
            }
        }
        
        return ans;
    }
};
