class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, best = 0;

        // Left to right: catches cases where ')' is in excess
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') left++;
            else right++;

            if (left == right) best = max(best, 2 * right);
            else if (right > left) left = right = 0;
        }

        left = right = 0;

        // Right to left: catches cases where '(' is in excess
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') left++;
            else right++;

            if (left == right) best = max(best, 2 * left);
            else if (left > right) left = right = 0;
        }

        return best;
    }
};