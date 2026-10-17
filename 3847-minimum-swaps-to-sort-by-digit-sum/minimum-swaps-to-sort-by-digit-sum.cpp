class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<pair<int,int>,int>> a;

        for (int i = 0; i < n; i++) {
            int x = nums[i], sum = 0;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            a.push_back({{sum, nums[i]}, i});
        }

        sort(a.begin(), a.end());

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || a[i].second == i) continue;

            int j = i, cnt = 0;
            while (!vis[j]) {
                vis[j] = true;
                j = a[j].second;
                cnt++;
            }

            ans += cnt - 1;
        }

        return ans;
    }
};