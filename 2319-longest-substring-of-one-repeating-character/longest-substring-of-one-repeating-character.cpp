class Solution {
    struct Node {
        int len, pref, suff, best;
        char lc, rc;

        Node(int l = 0, int p = 0, int s = 0, int b = 0,
             char left = 0, char right = 0)
            : len(l), pref(p), suff(s), best(b), lc(left), rc(right) {}
    };

    vector<Node> tree;
    string s;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node c;
        c.len = a.len + b.len;
        c.lc = a.lc;
        c.rc = b.rc;

        c.pref = a.pref;
        if (a.pref == a.len && a.rc == b.lc)
            c.pref += b.pref;

        c.suff = b.suff;
        if (b.suff == b.len && a.rc == b.lc)
            c.suff += a.suff;

        c.best = max(a.best, b.best);

        if (a.rc == b.lc)
            c.best = max(c.best, a.suff + b.pref);

        return c;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = Node(1, 1, 1, 1, s[l], s[l]);
            return;
        }

        int mid = (l + r) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int pos, char ch) {
        if (l == r) {
            tree[node] = Node(1, 1, 1, 1, ch, ch);
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(2 * node, l, mid, pos, ch);
        else
            update(2 * node + 1, mid + 1, r, pos, ch);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        this->s = s;
        int n = s.size();

        tree.resize(4 * n);
        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {
            int pos = queryIndices[i];
            char ch = queryCharacters[i];

            s[pos] = ch;
            update(1, 0, n - 1, pos, ch);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};