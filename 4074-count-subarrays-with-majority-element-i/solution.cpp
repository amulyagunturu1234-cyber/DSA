class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int result = 0;
        int prefixSum = 0;
        
        // freq[s] = how many times prefix sum 's' has appeared
        unordered_map<int, int> freq;
        freq[0] = 1; // empty prefix
        
        for (int i = 0; i < n; i++) {
            prefixSum += (nums[i] == target) ? 1 : -1;
            
            // We want subarrays where sum > 0
            // i.e., prefixSum[i] - prefixSum[j] > 0
            // i.e., prefixSum[j] < prefixSum[i]
            // Count all prefix sums strictly less than current
            for (auto& [key, cnt] : freq) {
                if (key < prefixSum) {
                    result += cnt;
                }
            }
            
            freq[prefixSum]++;
        }
        
        return result;
    }
};
