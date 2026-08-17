class Solution {
public:
    int n;
    vector<int> prefix;
    vector<vector<int>> dp;

    int solve(int l, int r) {
        // Only one stone -> cannot split
        if (l == r)
            return 0;

        // Already calculated
        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;

        int leftSum = 0;
        int rightSum = prefix[r + 1] - prefix[l];

        for (int k = l; k < r; k++) {

            // Move stoneValue[k] from right part to left part
            leftSum += prefix[k + 1] - prefix[k];
            rightSum -= prefix[k + 1] - prefix[k];

            if (leftSum < rightSum) {

                // Bob throws right part
                // We keep left part
                if (ans >= 2 * leftSum)
                    continue;

                ans = max(ans, leftSum + solve(l, k));

            }
            else if (leftSum > rightSum) {

                // Bob throws left part
                // We keep right part
                if (ans >= 2 * rightSum)
                    break;

                ans = max(ans, rightSum + solve(k + 1, r));

            }
            else {

                // Equal -> Alice can choose either part
                ans = max(ans,
                          max(leftSum + solve(l, k),
                              rightSum + solve(k + 1, r)));
            }
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {

        n = stoneValue.size();

        // Prefix sums
        prefix.assign(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stoneValue[i];

        // dp[l][r] = maximum score from stones l...r
        dp.assign(n, vector<int>(n, -1));

        return solve(0, n - 1);
    }
};