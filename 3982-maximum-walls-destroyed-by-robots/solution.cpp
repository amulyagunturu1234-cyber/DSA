class Solution {
public:
    int n;
    vector<array<int,2>> arr;
    vector<int> walls;
    vector<array<int,2>> f;

    int dfs(int i, int j) {
        if (i < 0) return 0;
        if (f[i][j] != -1) return f[i][j];

        long long left = (long long)arr[i][0] - arr[i][1];
        if (i > 0) left = max(left, (long long)arr[i-1][0] + 1);
        int l = (int)(lower_bound(walls.begin(), walls.end(), (int)left) - walls.begin());
        int r = (int)(lower_bound(walls.begin(), walls.end(), arr[i][0] + 1) - walls.begin());
        int ans = dfs(i - 1, 0) + (r - l);

        long long right = (long long)arr[i][0] + arr[i][1];
        if (i + 1 < n) {
            if (j == 0)
                right = min(right, (long long)arr[i+1][0] - arr[i+1][1] - 1);
            else
                right = min(right, (long long)arr[i+1][0] - 1);
        }
        l = (int)(lower_bound(walls.begin(), walls.end(), arr[i][0]) - walls.begin());
        r = (int)(lower_bound(walls.begin(), walls.end(), (int)right + 1) - walls.begin());
        ans = max(ans, dfs(i - 1, 1) + (r - l));

        return f[i][j] = ans;
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        n = robots.size();
        arr.resize(n);
        for (int i = 0; i < n; i++) arr[i] = {robots[i], distance[i]};
        sort(arr.begin(), arr.end());
        sort(walls.begin(), walls.end());
        this->walls = walls;
        f.assign(n, {-1, -1});
        return dfs(n - 1, 1);
    }
};
