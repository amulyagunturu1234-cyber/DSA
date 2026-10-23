class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = -1;  // all bits set (identity for AND)
        
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                k &= nums[i];
            }
        }
        
        return k == -1 ? 0 : k;
    }
};