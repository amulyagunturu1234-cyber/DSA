class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        // For each starting index, compute the minimal valid interval
        // (start, end) that contains all occurrences of every char inside it.
        vector<pair<int,int>> intervals;
        for (int i = 0; i < n; i++) {
            int start = i;
            int end = last[s[i] - 'a'];
            int j = start;
            bool valid = true;
            while (j <= end) {
                int c = s[j] - 'a';
                if (first[c] < start) { // char's first occurrence lies before start -> unusable
                    valid = false;
                    break;
                }
                end = max(end, last[c]);
                j++;
            }
            if (valid) intervals.push_back({start, end});
        }

        // Sort by end ascending; for equal end, prefer larger start (shorter interval)
        sort(intervals.begin(), intervals.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.second != b.second) return a.second < b.second;
            return a.first > b.first;
        });

        // Greedily pick non-overlapping intervals
        vector<string> result;
        int prevEnd = -1;
        for (auto& [start, end] : intervals) {
            if (start > prevEnd) {
                result.push_back(s.substr(start, end - start + 1));
                prevEnd = end;
            }
        }
        return result;
    }
};