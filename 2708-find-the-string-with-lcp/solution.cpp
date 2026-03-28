class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string word(n, ' ');
        
        // Greedily assign smallest possible character
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (word[i] != ' ') continue;
            if (c >= 26) return "";
            word[i] = 'a' + c++;
            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] > 0) word[j] = word[i];
            }
        }
        
        // Validate: fill lcp bottom-up and check
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word[i] == word[j]) {
                    int expected = (i == n-1 || j == n-1) ? 1 : lcp[i+1][j+1] + 1;
                    if (lcp[i][j] != expected) return "";
                } else {
                    if (lcp[i][j] != 0) return "";
                }
            }
        }
        
        return word;
    }
};
