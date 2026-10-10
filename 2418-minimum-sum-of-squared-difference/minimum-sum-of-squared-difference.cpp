class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        // cnt[d] = number of positions with difference d
        int maxD = 0;
        vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxD = max(maxD, diff[i]);
        }
        vector<long long> cnt(maxD + 1, 0);
        for (int d : diff) cnt[d]++;

        // Lower the highest difference level down, as far as k allows
        for (int d = maxD; d > 0 && k > 0; d--) {
            if (cnt[d] == 0) continue;

            if (cnt[d] <= k) {
                // Move all elements at level d down to d-1
                k -= cnt[d];
                cnt[d - 1] += cnt[d];
                cnt[d] = 0;
            } else {
                // Only some can move down: cnt[d] - k stay, k move to d-1
                cnt[d - 1] += k;
                cnt[d] -= k;
                k = 0;
            }
        }

        long long ans = 0;
        for (long long d = 1; d <= maxD; d++) {
            ans += cnt[d] * d * d;
        }
        return ans;
    }
};