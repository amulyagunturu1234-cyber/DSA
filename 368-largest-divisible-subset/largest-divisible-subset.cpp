class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<int> dp(n, 1);
        vector<int> parent(n, -1);

        int maxi = 0;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < i; j++) {

                if(nums[i] % nums[j] == 0) {

                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }

            if(dp[i] > dp[maxi]) {
                maxi = i;
            }
        }

        // Reconstruct answer
        vector<int> ans;

        while(maxi != -1) {
            ans.push_back(nums[maxi]);
            maxi = parent[maxi];
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};