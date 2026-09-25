class Solution {
public:

    set<string> solve(string &s, int &i) {
        set<string> ans;
        set<string> cur = {""};

        while (i < s.size() && s[i] != '}' && s[i] != ',') {

            set<string> part;

            if (s[i] == '{') {
                i++;                 // skip '{'

                while (true) {
                    set<string> temp = solve(s, i);

                    for (string x : temp)
                        part.insert(x);

                    if (s[i] == ',') {
                        i++;         // next option
                    }
                    else if (s[i] == '}') {
                        i++;         // close '}'
                        break;
                    }
                }
            }
            else {
                part.insert(string(1, s[i]));
                i++;
            }

            // Concatenate cur with part
            set<string> next;

            for (string a : cur) {
                for (string b : part) {
                    next.insert(a + b);
                }
            }

            cur = next;
        }

        return cur;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ans = solve(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};