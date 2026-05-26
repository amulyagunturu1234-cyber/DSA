class Solution {
public:
    int numberOfSpecialChars(string word) {
         unordered_set<char> seen(word.begin(), word.end());
        int cnt = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (seen.count(c) && seen.count(toupper(c))) {
                cnt++;
            }
        }
        return cnt;
    }
};
