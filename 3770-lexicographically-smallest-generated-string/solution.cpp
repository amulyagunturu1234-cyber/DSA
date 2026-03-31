class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int len = n + m - 1;
        
        // word filled with 'a' by default
        string word(len, 'a');
        vector<bool> fixed(len, false); // positions forced by a 'T' constraint
        
        // Step 1: Apply all 'T' constraints first
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (fixed[i + j] && word[i + j] != str2[j]) {
                        return ""; // conflict between two 'T' windows
                    }
                    word[i + j] = str2[j];
                    fixed[i + j] = true;
                }
            }
        }
        
        // Step 2: Verify and fix 'F' constraints
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                // Check if word[i..i+m-1] == str2 (which would be a violation)
                bool equal = true;
                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        equal = false;
                        break;
                    }
                }
                if (equal) {
                    // Need to make them differ. Change the last non-fixed char
                    // in this window to break equality (lexicographically minimal fix)
                    bool fixed_violation = true;
                    for (int j = m - 1; j >= 0; j--) {
                        if (!fixed[i + j]) {
                            // Change word[i+j] to something != str2[j]
                            word[i + j] = (str2[j] == 'a') ? 'b' : 'a';
                            fixed_violation = false;
                            break;
                        }
                    }
                    if (fixed_violation) return ""; // all positions fixed, can't change
                }
            }
        }
        
        return word;
    }
};
