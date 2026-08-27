class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        string res(n, ' ');
        vector<int> matchStack; // positions where we placed an exact match
        int pos = 0;
        bool success = false;

        // Advance as far as possible matching target exactly
        while (pos < n && cnt[target[pos] - 'a'] > 0) {
            cnt[target[pos] - 'a']--;
            res[pos] = target[pos];
            matchStack.push_back(pos);
            pos++;
        }

        while (true) {
            int found = -1;
            if (pos < n) {
                for (int c = target[pos] - 'a' + 1; c < 26; c++) {
                    if (cnt[c] > 0) { found = c; break; }
                }
            }

            if (found != -1) {
                // place the smallest greater letter here
                cnt[found]--;
                res[pos] = 'a' + found;
                // fill the rest with remaining letters, ascending
                int idx = pos + 1;
                for (int c = 0; c < 26; c++) {
                    while (cnt[c] > 0) {
                        res[idx++] = 'a' + c;
                        cnt[c]--;
                    }
                }
                success = true;
                break;
            }

            // couldn't bump up here — backtrack to the previous matched position
            if (matchStack.empty()) {
                success = false;
                break;
            }
            int prev = matchStack.back();
            matchStack.pop_back();
            cnt[target[prev] - 'a']++; // undo that exact match
            pos = prev;
        }

        return success ? res : "";
    }
};