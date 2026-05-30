#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<long long> t;
    SegTree(int n) : n(n), t(2*n, 0) {}
    void update(int i, long long v) {
        for (t[i+=n]=v; i>1; i>>=1)
            t[i>>1] = max(t[i], t[i^1]);
    }
    long long query(int l, int r) {
        long long res = 0;
        for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
            if (l&1) res = max(res, t[l++]);
            if (r&1) res = max(res, t[--r]);
        }
        return res;
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        // Collect ALL x values (both type 1 and type 2)
        vector<int> coords = {0};
        for (auto& q : queries) coords.push_back(q[1]);
        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());
        int m = coords.size();

        auto getIdx = [&](int v) {
            return (int)(lower_bound(coords.begin(), coords.end(), v) - coords.begin());
        };

        set<int> obs;
        obs.insert(0);
        obs.insert(2'000'000'001);

        // seg[i] = gap ending at coords[i] from its previous obstacle
        //        = coords[i] - prev_obstacle_strictly_before_coords[i]
        // ONLY meaningful/updated for obstacle positions.
        // Non-obstacle positions are never updated (stay 0 or initial).
        // For type-2 query at x: we only need max over obstacle positions in [0,x]
        // plus the tail gap (x - last_obs_leq_x).
        SegTree seg(m);
        // Origin (0) is an obstacle: gap before it = 0
        seg.update(0, 0LL);
        // All other positions start at 0 (unset)

        vector<bool> ans;

        for (auto& q : queries) {
            int type = q[0], x = q[1];
            int xi = getIdx(x);

            if (type == 1) {
                auto it = obs.upper_bound(x);
                int nxt = *it;
                --it;
                int prv = *it;

                obs.insert(x);

                // Gap ending AT x (from prv to x)
                seg.update(xi, (long long)(x - prv));

                // nxt's gap changes from (nxt - prv) to (nxt - x)
                // Only update if nxt is in our compressed coords
                if (nxt != 2'000'000'001) {
                    int ni = getIdx(nxt);
                    if (coords[ni] == nxt)
                        seg.update(ni, (long long)(nxt - x));
                }

            } else {
                int sz = q[2];

                // Tail gap: from last obstacle <= x to x
                auto it = obs.upper_bound(x);
                --it;
                long long tail = (long long)(x - *it);

                // Max gap from obstacle positions in [0, x]
                // seg[i] is set only for obstacle coords; others are 0 (harmless)
                long long best = max(seg.query(0, xi + 1), tail);

                ans.push_back(best >= (long long)sz);
            }
        }
        return ans;
    }
};
