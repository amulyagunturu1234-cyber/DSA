class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> suffixMin(n);

        suffixMin[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }

        int maxm = INT_MIN;

        for(int i = 0; i < n; i++) {
            maxm = max(maxm, nums[i]);

            int minm = suffixMin[i];

            if(maxm - minm <= k) {
                return i;
            }
        }

        return -1;
    }
};