class Solution {
public:
    int minimumPushes(string word) {
        int freq[26] = {0};
        for (char c : word) freq[c - 'a']++;
        
        sort(freq, freq + 26, greater<int>());
        
        int totalPushes = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break; // no more letters to place
            int pushesNeeded = (i / 8) + 1; // key needs this many presses for i-th letter assigned
            totalPushes += pushesNeeded * freq[i];
        }
        
        return totalPushes;
    }
};
