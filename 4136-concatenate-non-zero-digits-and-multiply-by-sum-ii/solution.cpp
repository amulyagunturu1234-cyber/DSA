class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;
        int m = s.size();
        
        vector<long long> P(m + 1, 0);      // concatenated value prefix
        vector<int> cnt(m + 1, 0);          // count of non-zero digits prefix
        vector<long long> sumPrefix(m + 1, 0); // digit sum prefix
        
        for (int i = 0; i < m; i++) {
            int d = s[i] - '0';
            if (d != 0) {
                P[i + 1] = (P[i] * 10 + d) % MOD;
                cnt[i + 1] = cnt[i] + 1;
            } else {
                P[i + 1] = P[i];
                cnt[i + 1] = cnt[i];
            }
            sumPrefix[i + 1] = sumPrefix[i] + d;
        }
        
        // precompute powers of 10 up to m (max possible count of non-zero digits)
        vector<long long> pow10(m + 1);
        pow10[0] = 1;
        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        
        vector<int> answer;
        answer.reserve(queries.size());
        
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            
            int diffCnt = cnt[r + 1] - cnt[l];
            long long x = (P[r + 1] - (P[l] * pow10[diffCnt]) % MOD + MOD) % MOD;
            long long sum = sumPrefix[r + 1] - sumPrefix[l];
            
            long long res = (x * (sum % MOD)) % MOD;
            answer.push_back((int)res);
        }
        
        return answer;
    }
};
