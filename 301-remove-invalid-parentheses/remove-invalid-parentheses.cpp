class Solution {
public:
    vector<string> ans;

    void dfs(string s, int index, int leftRemove, int rightRemove, int balance) {

        if (index == s.size()) {
            if (leftRemove == 0 && rightRemove == 0 && balance == 0)
                ans.push_back(s);
            return;
        }

        // Remove current character
        if (s[index] == '(' && leftRemove > 0) {
            if (index == 0 || s[index - 1] != '(')
                dfs(s.substr(0, index) + s.substr(index + 1),
                    index, leftRemove - 1, rightRemove, balance);
        }

        if (s[index] == ')' && rightRemove > 0) {
            if (index == 0 || s[index - 1] != ')')
                dfs(s.substr(0, index) + s.substr(index + 1),
                    index, leftRemove, rightRemove - 1, balance);
        }

        // Keep current character
        if (s[index] == '(')
            dfs(s, index + 1, leftRemove, rightRemove, balance + 1);

        else if (s[index] == ')') {
            if (balance > 0)
                dfs(s, index + 1, leftRemove, rightRemove, balance - 1);
        }
        else
            dfs(s, index + 1, leftRemove, rightRemove, balance);
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0, rightRemove = 0;

        // Find minimum number of removals
        for (char c : s) {
            if (c == '(')
                leftRemove++;

            else if (c == ')') {
                if (leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        dfs(s, 0, leftRemove, rightRemove, 0);

        return ans;
    }
}; 