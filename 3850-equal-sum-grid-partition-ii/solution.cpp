class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        long long total = 0;
        unordered_map<long long, int> totalFreq;

        for (auto &row : grid) {
            for (int val : row) {
                total += val;
                totalFreq[val]++;
            }
        }

        auto canRemove = [&](long long need, int r1, int r2, int c1, int c2,
                             unordered_map<long long,int>& freq) -> bool {

            if (need <= 0) return false;

            int rows = r2 - r1 + 1;
            int cols = c2 - c1 + 1;

            if (rows == 1 && cols == 1) return false;

            // 1 row
            if (rows == 1) {
                return grid[r1][c1] == need || grid[r1][c2] == need;
            }

            // 1 column
            if (cols == 1) {
                return grid[r1][c1] == need || grid[r2][c1] == need;
            }

            // full 2D → just check existence
            return freq.count(need);
        };

        // Horizontal cuts
        long long topSum = 0;
        unordered_map<long long,int> topFreq;

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                topSum += val;
                topFreq[val]++;
                totalFreq[val]--;
                if (totalFreq[val] == 0) totalFreq.erase(val);
            }

            long long bottomSum = total - topSum;

            if (topSum == bottomSum) return true;

            long long diff = topSum - bottomSum;

            if (diff > 0) {
                if (canRemove(diff, 0, i, 0, n-1, topFreq)) return true;
            } else {
                if (canRemove(-diff, i+1, m-1, 0, n-1, totalFreq)) return true;
            }
        }

        // Reset totalFreq for vertical
        totalFreq.clear();
        for (auto &row : grid)
            for (int val : row)
                totalFreq[val]++;

        // Vertical cuts
        long long leftSum = 0;
        unordered_map<long long,int> leftFreq;

        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                int val = grid[i][j];
                leftSum += val;
                leftFreq[val]++;
                totalFreq[val]--;
                if (totalFreq[val] == 0) totalFreq.erase(val);
            }

            long long rightSum = total - leftSum;

            if (leftSum == rightSum) return true;

            long long diff = leftSum - rightSum;

            if (diff > 0) {
                if (canRemove(diff, 0, m-1, 0, j, leftFreq)) return true;
            } else {
                if (canRemove(-diff, 0, m-1, j+1, n-1, totalFreq)) return true;
            }
        }

        return false;
    }
};
