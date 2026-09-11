class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {};

        for (int x : digits)
            freq[x]++;

        int ans = 0;

        for (int a = 1; a <= 9; a++) {       // first digit
            if (freq[a] == 0) continue;
            freq[a]--;

            for (int b = 0; b <= 9; b++) {   // second digit
                if (freq[b] == 0) continue;
                freq[b]--;

                for (int c = 0; c <= 8; c += 2) { // last digit even
                    if (freq[c] > 0)
                        ans++;
                }

                freq[b]++;
            }

            freq[a]++;
        }

        return ans;
    }
};