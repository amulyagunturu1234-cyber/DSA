class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        while (mn != 0) {
            int temp = mn;
            mn = mx % mn;
            mx = temp;
        }
        return mx;
    }
};
