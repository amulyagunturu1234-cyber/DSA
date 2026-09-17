class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> best(n + 1, 1e9);

        int ans = 1e9;
        int left = 0, sum = 0;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left++];
            }

            if (sum == target) {
                int len = right - left + 1;

                // best[left] is a subarray completely before current one
                if (best[left] != 1e9)
                    ans = min(ans, len + best[left]);

                best[right + 1] = min(best[right], len);
            }
            else {
                best[right + 1] = best[right];
            }
        }

        return ans == 1e9 ? -1 : ans;
    }
};