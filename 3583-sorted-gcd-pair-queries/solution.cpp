class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);
        for (int x : nums) freq[x]++;

        vector<long long> divisible(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            for (int j = d; j <= mx; j += d) {
                divisible[d] += freq[j];
            }
        }

        vector<long long> exact(mx + 1, 0);
        for (int d = mx; d >= 1; d--) {
            long long c = divisible[d];
            exact[d] = c * (c - 1) / 2;
            for (int j = d * 2; j <= mx; j += d) {
                exact[d] -= exact[j];
            }
        }

        vector<long long> prefix(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            prefix[d] = prefix[d - 1] + exact[d];
        }

        vector<int> ans;
        for (long long q : queries) {
            int l = 1, r = mx;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (prefix[mid] > q)
                    r = mid;
                else
                    l = mid + 1;
            }
            ans.push_back(l);
        }

        return ans;
    }
};
