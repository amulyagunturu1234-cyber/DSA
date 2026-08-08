class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<int> last(m, -1);

        // Find the last possible position for every
        // character of word2.
        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {

            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }

            i--;
        }

        vector<int> ans(m);

        bool mismatchUsed = false;
        j = 0;

        // Greedily choose the smallest possible index
        for (i = 0; i < n; i++) {

            if (j == m)
                break;

            // Normal matching character
            if (word1[i] == word2[j]) {

                ans[j] = i;
                j++;
            }

            // Use our one allowed mismatch
            else if (!mismatchUsed &&
                     (j == m - 1 || i < last[j + 1])) {

                mismatchUsed = true;

                ans[j] = i;
                j++;
            }
        }

        // Could not form the complete sequence
        if (j != m)
            return {};

        return ans;
    }
};