class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        
        // Step 1: Build height array (consecutive 1s from top)
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i-1][j];
                }
                // if matrix[i][j] == 0, keep it 0
            }
        }
        
        // Step 2: For each row, sort heights and compute max area
        for (int i = 0; i < m; i++) {
            vector<int> row = matrix[i]; // copy current row heights
            sort(row.begin(), row.end()); // ascending sort
            
            for (int j = 0; j < n; j++) {
                // width = number of columns from j to end = (n - j)
                // height = row[j] (minimum height in this window after sorting)
                int area = row[j] * (n - j);
                ans = max(ans, area);
            }
        }
        
        return ans;
    }
};
