class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int maxV = *max_element(nums.begin(), nums.end());
        
        // dp[g1][g2] = number of ways so far where current gcd of seq1 is g1,
        // gcd of seq2 is g2 (0 means that sequence is still empty)
        vector<vector<long long>> dp(maxV + 1, vector<long long>(maxV + 1, 0));
        dp[0][0] = 1;
        
        for (int num : nums) {
            vector<vector<long long>> ndp = dp; // handles "assign to neither"
            
            for (int g1 = 0; g1 <= maxV; g1++) {
                for (int g2 = 0; g2 <= maxV; g2++) {
                    long long val = dp[g1][g2];
                    if (!val) continue;
                    
                    // assign current num to seq1
                    int ng1 = (g1 == 0) ? num : __gcd(g1, num);
                    ndp[ng1][g2] = (ndp[ng1][g2] + val) % MOD;
                    
                    // assign current num to seq2
                    int ng2 = (g2 == 0) ? num : __gcd(g2, num);
                    ndp[g1][ng2] = (ndp[g1][ng2] + val) % MOD;
                }
            }
            
            dp = move(ndp);
        }
        
        long long ans = 0;
        // both sequences must be non-empty and have equal gcd
        for (int g = 1; g <= maxV; g++) {
            ans = (ans + dp[g][g]) % MOD;
        }
        
        return (int)ans;
    }
};
