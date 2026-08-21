class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        // Count how many distinct amounts <= x can be made
        auto countAmounts = [&](long long x) -> long long {
            long long ans = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                long long lcm = 1;
                int bits = 0;
                bool valid = true;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        long long g = std::gcd(lcm, (long long)coins[i]);

                        // Prevent overflow
                        __int128 newLcm =
                            (__int128)(lcm / g) * coins[i];

                        if (newLcm > x) {
                            valid = false;
                            break;
                        }

                        lcm = (long long)newLcm;
                    }
                }

                if (!valid)
                    continue;

                long long cnt = x / lcm;

                // Inclusion-Exclusion
                if (bits % 2 == 1)
                    ans += cnt;
                else
                    ans -= cnt;
            }

            return ans;
        };

        // The answer cannot be greater than
        // k times the smallest coin.
        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (countAmounts(mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};