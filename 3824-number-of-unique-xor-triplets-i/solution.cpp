class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return n;
        
        // number of bits needed to represent n
        int bits = 32 - __builtin_clz(n);
        return 1 << bits;
    }
};
