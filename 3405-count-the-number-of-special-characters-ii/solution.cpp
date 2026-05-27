class Solution {
public:
int numberOfSpecialChars(string word) {
    unordered_map<char, pair<int,int>> occ; // {first, last}

    for (int i = 0; i < word.size(); i++) {
        char c = word[i];
        if (!occ.count(c))
            occ[c].first = i;   // first occurrence
        occ[c].second = i;      // last occurrence
    }

    int cnt = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        char C = toupper(c);
        if (occ.count(c) && occ.count(C)) {
            // last lowercase must be before first uppercase
            if (occ[c].second < occ[C].first)
                cnt++;
        }
    }
    return cnt;
}
};
