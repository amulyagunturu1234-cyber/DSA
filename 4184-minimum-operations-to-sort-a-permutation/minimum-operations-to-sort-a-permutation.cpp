class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int best = INT_MAX;

        // Case A: nums is a rotation of 0,1,...,n-1
        bool a = true;
        for (int i = 0; i < n; i++)
            if (nums[i] != (nums[0] + i) % n) { a = false; break; }
        if (a) {
            int k = nums[0];
            if (k == 0) best = 0;
            else best = min(n - k, k + 2);   // left rotate (n-k) times, or reverse + left k + reverse
        }

        // Case B: nums is a rotation of n-1,...,1,0
        bool b = true;
        for (int i = 0; i < n; i++)
            if (nums[i] != ((nums[0] - i) % n + n) % n) { b = false; break; }
        if (b) {
            int k = (nums[0] + 1) % n;
            int cost = (k == 0) ? 1 : min(k + 1, n - k + 1);
            best = min(best, cost);
        }

        return best == INT_MAX ? -1 : best;
    }
};