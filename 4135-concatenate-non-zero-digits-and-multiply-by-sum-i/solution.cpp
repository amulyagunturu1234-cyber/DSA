class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string x;
        for (char c : s) {
            if (c != '0') x.push_back(c);
        }
        
        if (x.empty()) return 0;
        
        long long xVal = stoll(x);
        long long sum = 0;
        for (char c : x) {
            sum += (c - '0');
        }
        
        return xVal * sum;
    }
};
