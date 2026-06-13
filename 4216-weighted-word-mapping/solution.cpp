class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";
        
        for (const string& word : words) {
            int totalWeight = 0;
            
            for (char c : word) {
                totalWeight += weights[c - 'a'];
            }
            
            int mod = totalWeight % 26;
            // Reverse mapping: 0->'z', 1->'y', ..., 25->'a'
            char mapped = 'z' - mod;
            result += mapped;
        }
        
        return result;
    }
};
