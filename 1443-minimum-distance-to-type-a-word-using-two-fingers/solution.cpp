class Solution {
public:
    int minimumDistance(string word) {
        int n = word.size();
        
        // Get row and col for each character
        auto getPos = [](char c) -> pair<int,int> {
            int idx = c - 'A';
            return {idx / 6, idx % 6};
        };
        
        auto dist = [&](char a, char b) -> int {
            if (a == ' ') return 0; // finger not placed yet, moving is free
            auto [r1, c1] = getPos(a);
            auto [r2, c2] = getPos(b);
            return abs(r1 - r2) + abs(c1 - c2);
        };
        
        // dp[other] = min cost when one finger just typed current char,
        // other finger is at 'other' (using ' ' as "not placed")
        // 27 states: 26 letters + 1 for "not yet placed" = index 26
        
        // Encode: 0-25 = 'A'-'Z', 26 = not placed
        const int UNPLACED = 26;
        const int INF = 1e9;
        
        // dp[j] = min cost so far, where one finger is at word[i-1],
        // and the other finger is at position j (26 = unplaced)
        vector<int> dp(27, INF);
        dp[UNPLACED] = 0; // Initially both fingers unplaced, cost 0
        
        for (int i = 0; i < n; i++) {
            char cur = word[i];
            char prev = (i > 0) ? word[i-1] : ' ';
            vector<int> ndp(27, INF);
            
            for (int j = 0; j <= 26; j++) {
                if (dp[j] == INF) continue;
                
                char other = (j == 26) ? ' ' : (char)('A' + j);
                
                // Option 1: Move the finger that typed prev to cur
                // other finger stays at j
                int cost1 = dp[j] + dist(prev, cur);
                if (cost1 < ndp[j]) ndp[j] = cost1;
                
                // Option 2: Move the other finger to cur
                // prev finger now becomes the "other"
                int prevIdx = (i > 0) ? (word[i-1] - 'A') : UNPLACED;
                int cost2 = dp[j] + dist(other, cur);
                if (cost2 < ndp[prevIdx]) ndp[prevIdx] = cost2;
            }
            
            dp = ndp;
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};
