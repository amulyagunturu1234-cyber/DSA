class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> positions;
        
        for (int i = 0; i < nums.size(); i++) {
            positions[nums[i]].push_back(i);
        }
        
        int result = INT_MAX;
        
        for (auto& [val, indices] : positions) {
            if (indices.size() < 3) continue;
            
            // indices are already in sorted order
            // For sorted i < j < k: distance = 2*(k - i)
            // To minimize, use a sliding window of size 3
            for (int x = 0; x + 2 < indices.size(); x++) {
                int dist = 2 * (indices[x + 2] - indices[x]);
                result = min(result, dist);
            }
        }
        
        return result == INT_MAX ? -1 : result;
    }
};
