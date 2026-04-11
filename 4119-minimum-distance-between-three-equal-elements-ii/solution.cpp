class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        // Map each value to its list of indices
        unordered_map<int, vector<int>> positions;
        
        for (int i = 0; i < nums.size(); i++) {
            positions[nums[i]].push_back(i);
        }
        
        int ans = INT_MAX;
        
        for (auto& [val, idx] : positions) {
            if (idx.size() < 3) continue;
            
            // idx is already sorted (we inserted in order)
            // Slide a window of size 3 to find minimum span
            for (int i = 0; i + 2 < idx.size(); i++) {
                int dist = 2 * (idx[i + 2] - idx[i]);
                ans = min(ans, dist);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};
