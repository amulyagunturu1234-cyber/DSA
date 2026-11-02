class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        // Place the median at index n/2 in O(n) average time
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int median = nums[n / 2];

        int moves = 0;
        for (int x : nums) {
            moves += abs(x - median);
        }
        return moves;
    }
};