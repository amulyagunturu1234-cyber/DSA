class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0, hi = 0;  // min and max possible number of unmatched '('
        for (char c : s) {
            if (c == '(') {
                lo++;
                hi++;
            } else if (c == ')') {
                lo--;
                hi--;
            } else {  // '*'
                lo--;   // treat as ')'
                hi++;   // treat as '('
            }
            if (hi < 0) return false;  // too many ')' even with every '*' as '('
            if (lo < 0) lo = 0;        // can't have negative open count
        }
        return lo == 0;
    }
};