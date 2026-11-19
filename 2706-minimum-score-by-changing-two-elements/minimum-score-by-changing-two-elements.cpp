class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        return min({
            nums[n-1] - nums[2],  // Change 2 smallest
            nums[n-2] - nums[1],  // Change smallest and largest
            nums[n-3] - nums[0]   // Change 2 largest
        });
    }
};