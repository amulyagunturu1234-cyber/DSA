class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // Sort by start ascending; if starts are equal, put larger end first
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int count = 0;
        int maxEnd = INT_MIN;

        for (auto& interval : intervals) {
            int end = interval[1];
            // If current interval's end is greater than the max end seen so far,
            // it is NOT covered by any previous interval (since starts are sorted
            // and any interval that starts <= this one and ends >= this one would
            // have already set maxEnd >= end).
            if (end > maxEnd) {
                count++;
                maxEnd = end;
            }
            // else: this interval is covered by some previous interval, skip it
        }

        return count;
    }
};
