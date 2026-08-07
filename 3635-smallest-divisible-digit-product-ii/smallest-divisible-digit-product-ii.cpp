class Solution {
public:
    int dp2[10] = {0,0,1,0,2,0,1,0,3,0};
    int dp3[10] = {0,0,0,1,0,0,1,0,0,2};
    int dp5[10] = {0,0,0,0,0,1,0,0,0,0};
    int dp7[10] = {0,0,0,0,0,0,0,1,0,0};

    long long minP2P3Slots(long long need2, long long need3) {
        if (need2 < 0) need2 = 0;
        if (need3 < 0) need3 = 0;
        long long best = LLONG_MAX;
        long long kmax = need2 + need3;
        for (long long k = 0; k <= kmax; k++) {
            long long r2 = need2 - k; if (r2 < 0) r2 = 0;
            long long r3 = need3 - k; if (r3 < 0) r3 = 0;
            long long slots = k + (r2 + 2) / 3 + (r3 + 1) / 2;
            if (slots < best) best = slots;
        }
        return best;
    }

    long long minSlots(long long need2, long long need3, long long need5, long long need7) {
        if (need5 < 0) need5 = 0;
        if (need7 < 0) need7 = 0;
        return minP2P3Slots(need2, need3) + need5 + need7;
    }

    bool feasible(long long need2, long long need3, long long need5, long long need7, long long length) {
        return minSlots(need2, need3, need5, need7) <= length;
    }

    string buildSuffix(long long need2, long long need3, long long need5, long long need7, long long L) {
        string res;
        res.reserve(L);
        for (long long i = 0; i < L; i++) {
            long long remainingLen = L - i - 1;
            for (int d = 1; d <= 9; d++) {
                long long n2 = need2 - dp2[d];
                long long n3 = need3 - dp3[d];
                long long n5 = need5 - dp5[d];
                long long n7 = need7 - dp7[d];
                if (feasible(n2, n3, n5, n7, remainingLen)) {
                    res.push_back('0' + d);
                    need2 = n2 < 0 ? 0 : n2;
                    need3 = n3 < 0 ? 0 : n3;
                    need5 = n5 < 0 ? 0 : n5;
                    need7 = n7 < 0 ? 0 : n7;
                    break;
                }
            }
        }
        return res;
    }

    string smallestNumber(string num, long long t) {
        long long need2=0, need3=0, need5=0, need7=0;
        long long tt = t;
        while (tt % 2 == 0) { need2++; tt /= 2; }
        while (tt % 3 == 0) { need3++; tt /= 3; }
        while (tt % 5 == 0) { need5++; tt /= 5; }
        while (tt % 7 == 0) { need7++; tt /= 7; }
        if (tt != 1) return "-1";

        int n = num.size();

        // prefix sums so each k lookup is O(1)
        vector<long long> pre2(n+1,0), pre3(n+1,0), pre5(n+1,0), pre7(n+1,0);
        vector<int> firstZero(n+1, -1); // firstZero[i] = index of first '0' in num[0..i-1], or -1 if none
        int fz = -1;
        for (int i = 0; i < n; i++) {
            int d = num[i] - '0';
            pre2[i+1] = pre2[i] + dp2[d];
            pre3[i+1] = pre3[i] + dp3[d];
            pre5[i+1] = pre5[i] + dp5[d];
            pre7[i+1] = pre7[i] + dp7[d];
            if (d == 0 && fz == -1) fz = i;
            firstZero[i+1] = fz;
        }

        bool numHasZero = (fz != -1);

        if (!numHasZero) {
            if (pre2[n] >= need2 && pre3[n] >= need3 && pre5[n] >= need5 && pre7[n] >= need7) {
                return num;
            }
        }

        for (int k = n - 1; k >= 0; k--) {
            // prefix num[0..k-1] must be zero-free
            if (firstZero[k] != -1) continue; // there's a zero within [0,k-1]

            long long p2 = pre2[k], p3 = pre3[k], p5 = pre5[k], p7 = pre7[k];

            int origDigit = num[k] - '0';
            for (int d = origDigit + 1; d <= 9; d++) {
                long long n2 = need2 - p2 - dp2[d];
                long long n3 = need3 - p3 - dp3[d];
                long long n5 = need5 - p5 - dp5[d];
                long long n7 = need7 - p7 - dp7[d];
                long long remainingLen = n - k - 1;
                if (feasible(n2, n3, n5, n7, remainingLen)) {
                    string prefix = num.substr(0, k);
                    prefix.push_back('0' + d);
                    string suffix = buildSuffix(n2, n3, n5, n7, remainingLen);
                    return prefix + suffix;
                }
            }
        }

        long long base = minSlots(need2, need3, need5, need7);
        long long L = max((long long)(n + 1), base);

        return buildSuffix(need2, need3, need5, need7, L);
    }
};