class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total = 0;
        
        for (int n = num1; n <= num2; n++) {
            string s = to_string(n);
            int len = s.size();
            
            // Numbers with fewer than 3 digits have waviness 0
            if (len < 3) continue;
            
            // Check middle digits (index 1 to len-2)
            for (int i = 1; i < len - 1; i++) {
                int prev = s[i-1] - '0';
                int curr = s[i]   - '0';
                int next = s[i+1] - '0';
                
                // Peak: strictly greater than both neighbors
                if (curr > prev && curr > next) total++;
                // Valley: strictly less than both neighbors
                else if (curr < prev && curr < next) total++;
            }
        }
        
        return total;
    }
};
