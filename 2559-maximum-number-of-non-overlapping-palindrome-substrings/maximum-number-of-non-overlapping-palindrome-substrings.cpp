class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<char> pal(n, false);
        vector<int> dp(n + 1, 0);

        for (int r = 0; r < n; r++) {
            dp[r + 1] = dp[r];  // don't take anything ending at r

            for (int l = 0; l <= r; l++) {

                if (s[l] == s[r] && (r - l < 2 || pal[l + 1])) {
                    pal[l] = true;

                    if (r - l + 1 >= k)
                        dp[r + 1] = max(dp[r + 1], dp[l] + 1);
                }
                else {
                    pal[l] = false;
                }
            }
        }

        return dp[n];
    }
};