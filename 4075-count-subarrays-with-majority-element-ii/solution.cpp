class Solution {
private:
    vector<long long> bit;
    int sz;
    
    void update(int i) {
        for (i++; i <= sz; i += i & (-i))
            bit[i]++;
    }
    
    long long query(int i) { // sum [0..i]
        long long s = 0;
        for (i++; i > 0; i -= i & (-i))
            s += bit[i];
        return s;
    }

public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        sz = 2 * n + 2;
        bit.assign(sz + 1, 0);
        
        int offset = n; // shift prefix sums to be non-negative
        long long ans = 0;
        int prefix = 0;
        
        update(prefix + offset); // prefix[0] = 0
        
        for (int i = 0; i < n; i++) {
            prefix += (nums[i] == target) ? 1 : -1;
            
            // Count previous prefix sums strictly less than current
            // i.e., query sum in range [0, prefix-1+offset]
            if (prefix - 1 + offset >= 0)
                ans += query(prefix - 1 + offset);
            
            update(prefix + offset);
        }
        
        return ans;
    }
};
