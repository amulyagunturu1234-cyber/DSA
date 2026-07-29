class Solution {
public:
    const long long CAP = (long long)4e18;
    
    // Safe multiply: returns CAP if overflow would occur
    long long safeMul(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        if (a > CAP / b) return CAP; // check BEFORE multiplying
        return a * b;
    }
    
    string smallestPalindrome(string s, long long k) {
        int n = s.size();
        int half = n / 2;
        bool oddMid = (n % 2 == 1);
        
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;
        
        int halfCnt[26] = {0};
        int midChar = -1;
        for (int i = 0; i < 26; i++) {
            if (oddMid && cnt[i] % 2 == 1) {
                midChar = i;
            }
            halfCnt[i] = cnt[i] / 2;
        }
        
        // Count multinomial permutations of counts array, capped at CAP, no overflow
        auto totalPerms = [&](int counts[26], int total) -> long long {
            if (total == 0) return 1;
            
            // Build numerator = total! but divide by each counts[i]! as we go,
            // interleaving multiply/divide to keep numbers small and avoid overflow.
            // We do this by walking positions 1..total, multiplying by "current top of factorial"
            // Simpler stable approach: compute via building up factorial ratio incrementally.
            
            // Sort counts descending isn't necessary. Standard trick:
            // result = total! / (c1! * c2! * ... )
            // Compute by iterating i from 1 to total, multiply result by i,
            // then for each count cj, divide out its factorial contribution at the right time.
            // Easiest safe way: use running product with early cap check, and divide by
            // factorials of each count separately once computed safely (counts are small).
            
            // Since counts[i] <= n (small, e.g. <= 1e5), compute denom factorials directly,
            // but denom also might overflow — so use safeMul with cap there too,
            // and only divide when denom fits (if denom capped, treat whole result as capped safely
            // using log-based fallback).
            
            // Use log-gamma first to decide if it's safe to compute exactly:
            double logResult = lgamma((double)total + 1);
            for (int i = 0; i < 26; i++) {
                if (counts[i] > 0) logResult -= lgamma((double)counts[i] + 1);
            }
            if (logResult > 43.5) { // log(4e18) ~ 43.4
                return CAP;
            }
            
            // Safe to compute exactly now — numerator won't exceed CAP by the log check,
            // but intermediate steps of naive factorial(total) might still overflow
            // (since total! itself could be huge even if the ratio is small).
            // So instead compute the multinomial coefficient incrementally:
            // result = C(total, counts[0]) * C(total-counts[0], counts[1]) * ...
            
            long long result = 1;
            int remaining = total;
            for (int i = 0; i < 26; i++) {
                if (counts[i] == 0) continue;
                // multiply result by C(remaining, counts[i])
                // C(remaining, c) = product_{j=1}^{c} (remaining - c + j) / j
                long long comb = 1;
                for (int j = 1; j <= counts[i]; j++) {
                    comb = safeMul(comb, (remaining - counts[i] + j));
                    comb /= j; // safe since comb*(...)/j is always integer at each step (standard trick)
                    if (comb >= CAP) { comb = CAP; break; }
                }
                result = safeMul(result, comb);
                remaining -= counts[i];
                if (result >= CAP) return CAP;
            }
            return result;
        };
        
        long long total = totalPerms(halfCnt, half);
        if (total < k) return "";
        
        string leftHalf = "";
        int remaining = half;
        int curCnt[26];
        for (int i = 0; i < 26; i++) curCnt[i] = halfCnt[i];
        
        for (int pos = 0; pos < half; pos++) {
            for (int c = 0; c < 26; c++) {
                if (curCnt[c] == 0) continue;
                curCnt[c]--;
                long long perms = totalPerms(curCnt, remaining - 1);
                if (perms >= k) {
                    leftHalf += ('a' + c);
                    remaining--;
                    goto nextPos;
                } else {
                    k -= perms;
                    curCnt[c]++;
                }
            }
            nextPos:;
        }
        
        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());
        
        string result = leftHalf;
        if (oddMid) result += (char)('a' + midChar);
        result += rightHalf;
        
        return result;
    }
};
