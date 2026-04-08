class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;  // 1,000,000,007  (NOT 10^5 + 7)
        
        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = (1LL * nums[idx] * v) % MOD;
            }
        }
        
        int xorSum = 0;
        for (int x : nums) {
            xorSum ^= x;
        }
        return xorSum;
    }
};
