class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
         int n = nums.size();

        long long sum = 0;
        long long curr = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            curr += (long long)i * nums[i];
        }// for sum and f(0)
        long long ans = curr;
         for(int k = 0; k < n - 1; k++) {

            curr = curr + sum - (long long)n * nums[n - k - 1];

            ans = max(ans, curr);
        }
        return ans;
    }
};