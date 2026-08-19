class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        // Mark reserved seats using a bitmask
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            // Only seats 2 to 9 matter
            if (col >= 2 && col <= 9)
                mp[row] |= (1 << (col - 2));
        }

        // Every completely empty row can fit 2 groups
        int ans = (n - mp.size()) * 2;

        for (auto &[row, mask] : mp) {
            // Seats 2,3,4,5
            bool left = (mask & 15) == 0;

            // Seats 4,5,6,7
            bool middle = (mask & 60) == 0;

            // Seats 6,7,8,9
            bool right = (mask & 240) == 0;

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};