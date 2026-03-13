class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
         auto maxReduction = [](long long T, long long wt) -> long long {
            // wt * x*(x+1)/2 <= T
            // x*(x+1) <= 2T/wt
            // x ~ sqrt(2T/wt)
            long long lo = 0, hi = 1e6;
            while (lo < hi) {
                long long mid = (lo + hi + 1) / 2;
                // Check if mid*(mid+1)/2 * wt <= T
                // Use __int128 to avoid overflow
                __int128 cost = (__int128)wt * mid * (mid + 1) / 2;
                if (cost <= (__int128)T)
                    lo = mid;
                else
                    hi = mid - 1;
            }
            return lo;
        };
        
        auto canFinish = [&](long long T) -> bool {
            long long totalReduction = 0;
            for (int wt : workerTimes) {
                totalReduction += maxReduction(T, wt);
                if (totalReduction >= mountainHeight) return true;
            }
            return false;
        };
        
        // Binary search bounds
        // Min time: 0
        // Max time: worst worker * mountainHeight*(mountainHeight+1)/2
        long long lo = 0;
        long long maxWt = *max_element(workerTimes.begin(), workerTimes.end());
        long long hi = (long long)maxWt * mountainHeight * (mountainHeight + 1) / 2;
        
        while (lo < hi) {
            long long mid = (lo + hi) / 2;
            if (canFinish(mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        
        return lo;
    }
};
