class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k);
        vector<long long> dp(k);

        for (int num : nums) {
            vector<long long> ndp(k);

            // Start a new subarray with only num
            ndp[num % k] = 1;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                int nr = (r * (num % k)) % k;
                ndp[nr] += dp[r];
            }

            // Add all subarrays ending here to answer
            for (int r = 0; r < k; r++) {
                ans[r] += ndp[r];
            }

            dp = ndp;
        }

        return ans;
    }
};