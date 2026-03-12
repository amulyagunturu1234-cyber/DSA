class Solution {
public:
    struct DSU {
        vector<int> parent, rank;
        DSU(int n) {
            parent.resize(n);
            rank.assign(n, 0);
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
        bool unite(int a, int b) {
            a = find(a); b = find(b);
            if (a == b) return false;
            if (rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b]) rank[a]++;
            return true;
        }
    };

    int n_nodes;

    bool canAchieve(int target, int k, vector<vector<int>>& mandatory, vector<vector<int>>& optional) {
        DSU dsu(n_nodes);

        // Mandatory edges cannot be upgraded - if below target, impossible
        for (auto& e : mandatory) {
            if (e[2] < target) return false;
            dsu.unite(e[0], e[1]);
        }

        int comp = 0;
        for (int i = 0; i < n_nodes; i++)
            if (dsu.find(i) == i) comp++;

        if (comp == 1) return true;

        int upgradesUsed = 0;

        // First pass: edges already meeting target (no upgrade needed)
        for (auto& e : optional) {
            if (e[2] >= target) {
                if (dsu.unite(e[0], e[1])) {
                    comp--;
                    if (comp == 1) return true;
                }
            }
        }

        // Second pass: edges needing 1 upgrade to meet target
        for (auto& e : optional) {
            if (e[2] < target && (long long)e[2] * 2 >= target) {
                if (dsu.unite(e[0], e[1])) {
                    upgradesUsed++;
                    if (upgradesUsed > k) return false;
                    comp--;
                    if (comp == 1) return true;
                }
            }
        }

        return comp == 1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        n_nodes = n;

        vector<vector<int>> mandatory, optional;
        for (auto& e : edges) {
            if (e[3] == 1) mandatory.push_back(e);
            else optional.push_back(e);
        }

        // FIX 1: mandatory edges forming a cycle = impossible
        {
            DSU dsu(n);
            for (auto& e : mandatory) {
                if (!dsu.unite(e[0], e[1])) return -1;
            }
        }

        // Sort optional descending by strength
        sort(optional.begin(), optional.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2];
        });

        // FIX 2: check if spanning tree is possible at all
        {
            DSU dsu(n);
            for (auto& e : mandatory) dsu.unite(e[0], e[1]);
            for (auto& e : optional) dsu.unite(e[0], e[1]);
            int comp = 0;
            for (int i = 0; i < n; i++) if (dsu.find(i) == i) comp++;
            if (comp > 1) return -1;
        }

        // Collect all candidate answer values (original + doubled optional strengths)
        vector<int> candidates;
        for (auto& e : mandatory) candidates.push_back(e[2]);
        for (auto& e : optional) {
            candidates.push_back(e[2]);
            candidates.push_back(e[2] * 2);
        }
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

        // Binary search on the answer
        int lo = 0, hi = (int)candidates.size() - 1, ans = candidates[0];
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (canAchieve(candidates[mid], k, mandatory, optional)) {
                ans = candidates[mid];
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};

