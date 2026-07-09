class Solution {
public:
    vector<int> parent, rank_;

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (rank_[a] < rank_[b]) swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b]) rank_[a]++;
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                       vector<vector<int>>& queries) {
        parent.resize(n);
        rank_.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;

        // nums is sorted non-decreasing, so only need to check consecutive elements
        for (int i = 0; i + 1 < n; i++) {
            if (nums[i + 1] - nums[i] <= maxDiff) {
                unite(i, i + 1);
            }
        }

        vector<bool> answer;
        answer.reserve(queries.size());
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            answer.push_back(find(u) == find(v));
        }
        return answer;
    }
};
