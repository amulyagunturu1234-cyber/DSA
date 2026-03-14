class Solution {
    private:   
    void backtrack(string& current, int n, int k) {
        if (current.size() == n) {
            count++;
            if (count == k) {
                result = current;
            }
            return;
        }
        
        for (char c = 'a'; c <= 'c'; c++) {
            // Skip if same as last character (happy string condition)
            if (!current.empty() && current.back() == c) continue;
            
            current.push_back(c);
            backtrack(current, n, k);
            
            // Early exit if found
            if (!result.empty()) return;
            
            current.pop_back();
        }
    }
public:

    string result;
    int count;
    string getHappyString(int n, int k) {
         int total = 3 * (1 << (n - 1));
        if (k > total) return "";
        
        result = "";
        count = 0;
        string current = "";
        backtrack(current, n, k);
        
        return result;
    }
};
