class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;

        // Find the bitmask: all 1s with same bit-length as n
        // e.g. n=5 (101) -> mask=7 (111)
        int mask = 1;
        while (mask < n)
            mask = (mask << 1) | 1;

        // XOR with mask flips all bits
        return mask ^ n;
    }
};
