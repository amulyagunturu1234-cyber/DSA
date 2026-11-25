
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        const long long M1 = 1000000007;
        const long long M2 = 1000000009;
        const long long B1 = 911382323;
        const long long B2 = 972663749;

        vector<long long> h1(n + 1, 0), h2(n + 1, 0);
        vector<long long> p1(n + 1, 1), p2(n + 1, 1);

        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * B1 + nums[i]) % M1;
            h2[i + 1] = (h2[i] * B2 + nums[i]) % M2;

            p1[i + 1] = p1[i] * B1 % M1;
            p2[i + 1] = p2[i] * B2 % M2;
        }

        auto check = [&](int len) {
            unordered_map<long long, int> mp;
            mp.reserve(n * 2);

            for (int i = 0; i + len <= n; i++) {
                int j = i + len;

                long long x = (h1[j] - h1[i] * p1[len] % M1 + M1) % M1;
                long long y = (h2[j] - h2[i] * p2[len] % M2 + M2) % M2;

                long long key = x * M2 + y;
                mp[key]++;
            }

            for (auto &it : mp) {
                if (it.second == 1)
                    return true;
            }

            return false;
        };

        int low = 1, high = n;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (check(mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};
