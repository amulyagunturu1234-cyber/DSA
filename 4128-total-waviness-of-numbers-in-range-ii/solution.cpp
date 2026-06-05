#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countUpTo(long long num) {
        if (num <= 0) return 0;
        string s = to_string(num);
        int n = s.size();
        
        using pll = pair<long long, long long>;
        vector<vector<vector<vector<pll>>>> dp2(2, vector<vector<vector<pll>>>(2, vector<vector<pll>>(10, vector<pll>(4, {0,0}))));
        dp2[1][0][0][0] = {1, 0};
        
        for (int pos = 0; pos < n; pos++) {
            vector<vector<vector<vector<pll>>>> ndp2(2, vector<vector<vector<pll>>>(2, vector<vector<pll>>(10, vector<pll>(4, {0,0}))));
            int limit = s[pos] - '0';
            
            for (int tight = 0; tight <= 1; tight++) {
                for (int started = 0; started <= 1; started++) {
                    for (int prev = 0; prev <= 9; prev++) {
                        for (int trend = 0; trend <= 3; trend++) {
                            auto [cnt, wav] = dp2[tight][started][prev][trend];
                            if (cnt == 0) continue;
                            
                            int maxD = tight ? limit : 9;
                            for (int d = 0; d <= maxD; d++) {
                                int nTight = tight && (d == maxD);
                                
                                if (!started) {
                                    if (d == 0) {
                                        ndp2[nTight][0][0][0].first += cnt;
                                        ndp2[nTight][0][0][0].second += wav;
                                    } else {
                                        ndp2[nTight][1][d][0].first += cnt;
                                        ndp2[nTight][1][d][0].second += wav;
                                    }
                                } else {
                                    int nTrend;
                                    if (d > prev) nTrend = 1;
                                    else if (d < prev) nTrend = 2;
                                    else nTrend = 3;
                                    
                                    long long addWav = 0;
                                    if (trend != 0) {
                                        if (trend == 1 && nTrend == 2) addWav = cnt;
                                        if (trend == 2 && nTrend == 1) addWav = cnt;
                                    }
                                    
                                    ndp2[nTight][1][d][nTrend].first += cnt;
                                    ndp2[nTight][1][d][nTrend].second += wav + addWav;
                                }
                            }
                        }
                    }
                }
            }
            dp2 = ndp2;
        }
        
        long long total = 0;
        for (int tight = 0; tight <= 1; tight++)
            for (int prev = 0; prev <= 9; prev++)
                for (int trend = 0; trend <= 3; trend++)
                    total += dp2[tight][1][prev][trend].second;
        
        return total;
    }
    
    long long totalWaviness(long long num1, long long num2) {
        return countUpTo(num2) - countUpTo(num1 - 1);
    }
};
