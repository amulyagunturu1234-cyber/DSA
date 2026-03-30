class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int even1[26] = {}, odd1[26] = {};
        int even2[26] = {}, odd2[26] = {};
        
        for (int i = 0; i < s1.size(); i++) {
            if (i % 2 == 0) { even1[s1[i]-'a']++; even2[s2[i]-'a']++; }
            else             { odd1[s1[i]-'a']++;  odd2[s2[i]-'a']++;  }
        }
        
        for (int c = 0; c < 26; c++)
            if (even1[c] != even2[c] || odd1[c] != odd2[c]) return false;
        
        return true;
    }
};
