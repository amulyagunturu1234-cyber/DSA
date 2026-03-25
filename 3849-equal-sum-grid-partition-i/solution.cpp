class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        long long totalSum = 0;
        for (auto& row : grid)
            for (int val : row)
                totalSum += val;
        
        // If total is odd, no equal partition possible
        if (totalSum % 2 != 0) return false;
        long long half = totalSum / 2;
        
        // Check horizontal cuts (after row i)
        long long rowSum = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int val : grid[i])
                rowSum += val;
            if (rowSum == half) return true;
        }
        
        // Check vertical cuts (after col j)
        long long colSum = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++)
                colSum += grid[i][j];
            if (colSum == half) return true;
        }
        
        return false;
    }
};
