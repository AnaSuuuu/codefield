#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;

struct Ans {
    int total, llen, rlen, mxlen;
    Ans(int len = 0) : total(len), llen(0), rlen(0), mxlen(0) {}
    void init() { total = llen = rlen = mxlen = 1; }
    friend Ans operator+(const Ans& a, const Ans& b) {
        Ans res;
        res.total = a.total + b.total;
        res.llen = a.llen, res.rlen = b.rlen;
        if (a.llen == a.total) {
            res.llen += b.llen;
        }
        if (b.rlen == b.total) {
            res.rlen += a.rlen;
        }
        res.mxlen = max({a.mxlen, b.mxlen, a.rlen + b.llen});
        return res;
    }
    Ans swap() {
        Ans res = *this;
        std::swap(res.llen, res.rlen);
        return res;
    }
};

struct Segt {
    struct T {
        int ls, rs;
        Ans ans;
        T() : ls(0), rs(0) {}
    };
    vector<T> t;
    int n;
    Segt(int n) : t(1) { this->n = n; }
    int insert(int v, int loc) { return insert(v, loc, 1, n); }
    int copy(int u, int v, int cl, int cr) { return copy(u, v, cl, cr, 1, n); }
    int query_left(int v, int len, Ans& last, int ql, int qr) {
        return query_left(v, len, last, ql, qr, 1, n);
    }
    int query_right(int v, int len, Ans& last, int ql, int qr) {
        return query_right(v, len, last, ql, qr, 1, n);
    }
    int newnode(int l, int r, T val) {
        int res = t.size();
        t.emplace_back();
        t[res] = val, t[res].ans.total = r - l + 1;
        return res;
    }

#define mid ((l + r) >> 1)
    void pu(int v, int l, int r) {
        if (!t[v].ls && !t[v].rs) {
            t[v].ans = Ans(r - l + 1);
        } else if (!t[v].ls) {
            t[v].ans = Ans(mid - l + 1) + t[t[v].rs].ans;
        } else if (!t[v].rs) {
            t[v].ans = t[t[v].ls].ans + Ans(r - mid);
        } else {
            t[v].ans = t[t[v].ls].ans + t[t[v].rs].ans;
        }
    }
    int insert(int v, int loc, int l, int r) {
        int u = newnode(l, r, t[v]);
        if (l == r) {
            t[u].ans.init();
        } else {
            if (loc <= mid) {
                t[u].ls = insert(t[u].ls, loc, l, mid);
            } else {
                t[u].rs = insert(t[u].rs, loc, mid + 1, r);
            }
            pu(u, l, r);
        }
        return u;
    }
    int copy(int u, int v, int cl, int cr, int l, int r) {
        if (cl <= l && cr >= r) {
            return v;
        } else {
            u = newnode(l, r, t[u]);
            if (cl <= mid) {
                t[u].ls = copy(t[u].ls, t[v].ls, cl, cr, l, mid);
            }
            if (cr > mid) {
                t[u].rs = copy(t[u].rs, t[v].rs, cl, cr, mid + 1, r);
            }
            pu(u, l, r);
            return u;
        }
    }

    int query_left(int v, int len, Ans& last, int ql, int qr, int l, int r) {
        if (ql <= l && qr >= r) {
            if (v == 0) {
                last = last + Ans(r - l + 1);
            } else {
                if (last.rlen + t[v].ans.llen >= len) {
                    return last.total - last.rlen;
                } else if (t[v].ans.mxlen >= len) {
                    return query_left(v, len) + last.total;
                } else {
                    last = last + t[v].ans;
                }
            }
            return -inf;
        } else {
            int res = -inf;
            if (ql <= mid) {
                res = query_left(t[v].ls, len, last, ql, qr, l, mid);
                if (res >= 0) {
                    return res;
                }
            }
            if (qr > mid) {
                res = query_left(t[v].rs, len, last, ql, qr, mid + 1, r);
            }
            return res;
        }
    }
    int query_left(int v, int l) {
        if (t[v].ans.mxlen < l) {
            return -inf;
        }
        if (t[v].ans.llen >= l) {
            return 0;
        }
        int ls = t[v].ls, rs = t[v].rs;
        if (t[ls].ans.mxlen >= l) {
            return query_left(ls, l);
        }
        if (ls && t[ls].ans.rlen + t[rs].ans.llen >= l) {
            return t[ls].ans.total - t[ls].ans.rlen;
        }
        return t[v].ans.total - t[rs].ans.total + query_left(rs, l);
    }

    int query_right(int v, int len, Ans& last, int ql, int qr, int l, int r) {
        if (ql <= l && qr >= r) {
            if (v == 0) {
                last = last + Ans(r - l + 1);
            } else {
                if (last.rlen + t[v].ans.rlen >= len) {
                    return last.total - last.rlen;
                } else if (t[v].ans.mxlen >= len) {
                    return query_right(v, len) + last.total;
                } else {
                    last = last + t[v].ans.swap();
                }
            }
            return -inf;
        } else {
            int res = -inf;
            if (qr > mid) {
                res = query_right(t[v].rs, len, last, ql, qr, mid + 1, r);
                if (res >= 0) {
                    return res;
                }
            }
            if (ql <= mid) {
                res = query_right(t[v].ls, len, last, ql, qr, l, mid);
            }
            return res;
        }
    }
    int query_right(int v, int l) {
        if (t[v].ans.mxlen < l) {
            return -inf;
        }
        if (t[v].ans.rlen >= l) {
            return 0;
        }
        int ls = t[v].ls, rs = t[v].rs;
        if (t[rs].ans.mxlen >= l) {
            return query_right(rs, l);
        }
        if (rs && t[rs].ans.llen + t[ls].ans.rlen >= l) {
            return t[rs].ans.total - t[rs].ans.llen;
        }
        return t[v].ans.total - t[ls].ans.total + query_right(ls, l);
    }
#undef mid
};

struct Tree {
    int n;
    vector<vector<int>> e;
    vector<int> a, fa, dep, sz, wson, top, dfn, id, rt;
    Segt tr;
    Tree(int n)
        : e(n + 1),
          a(n + 1),
          fa(n + 1),
          dep(n + 1),
          sz(n + 1),
          wson(n + 1),
          top(n + 1),
          dfn(n + 1),
          id(1),
          rt(n + 2),
          tr(n) {
        this->n = n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            e[u].emplace_back(v);
            e[v].emplace_back(u);
        }
        init(1, 1);
        build(1, 1);
        build_segt();
    }
    void build_segt() {
        vector<vector<int>> wid(n + 1);
        for (int i = 1; i <= n; i++) {
            wid[a[i]].emplace_back(dfn[i]);
        }
        for (int i = n; i >= 1; i--) {
            rt[i] = rt[i + 1];
            for (auto j : wid[i]) {
                rt[i] = tr.insert(rt[i], j);
            }
        }
    }
    void init(int v, int f) {
        dep[v] = dep[f] + 1;
        fa[v] = f;
        sz[v] = 1;
        for (auto u : e[v]) {
            if (u != f) {
                init(u, v);
                sz[v] += sz[u];
                if (wson[v] == 0 || sz[u] > sz[wson[v]]) {
                    wson[v] = u;
                }
            }
        }
    }
    void build(int v, int t) {
        top[v] = t;
        dfn[v] = id.size();
        id.emplace_back(v);
        if (wson[v]) {
            build(wson[v], t);
        }
        for (auto u : e[v]) {
            if (u != fa[v] && u != wson[v]) {
                build(u, u);
            }
        }
    }
    void add(int u, int v, int x, int d) {
        auto work = [&](int l, int r) {
            if (d == 1) {
                rt[x + 1] = tr.copy(rt[x + 1], rt[x], l, r);
            } else {
                rt[x] = tr.copy(rt[x], rt[x + 1], l, r);
            }
        };
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) {
                swap(u, v);
            }
            int l = dfn[top[u]], r = l + dep[u] - dep[top[u]];
            work(l, r);
            u = fa[top[u]];
        }
        if (dep[u] < dep[v]) {
            swap(u, v);
        }
        int l = dfn[v], r = l + dep[u] - dep[v];
        work(l, r);
    }
    int query(int u, int v, int len, int y) {
        vector<pair<int, int>> qu, qv;
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                int l = dfn[top[u]], r = l + dep[u] - dep[top[u]];
                qu.emplace_back(r, l);
                u = fa[top[u]];
            } else {
                int l = dfn[top[v]], r = l + dep[v] - dep[top[v]];
                qv.emplace_back(l, r);
                v = fa[top[v]];
            }
        }
        if (dep[u] > dep[v]) {
            int l = dfn[v], r = l + dep[u] - dep[v];
            qu.emplace_back(r, l);
        } else {
            int l = dfn[u], r = l + dep[v] - dep[u];
            qv.emplace_back(l, r);
        }
        reverse(qv.begin(), qv.end());
        for (auto r : qv) {
            qu.emplace_back(r);
        }
        Ans last;
        int res = -inf;
        for (auto& [l, r] : qu) {
            if (l <= r) {
                res = tr.query_left(rt[y], len, last, l, r);
            } else {
                res = tr.query_right(rt[y], len, last, r, l);
            }
            if (res >= 0) {
                break;
            }
        }
        return max(-1, res);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    Tree tr(n);
    for (int i = 1; i <= m; i++) {
        int op, u, v, x, y, l;
        cin >> op >> u >> v;
        if (op == 1 || op == 2) {
            cin >> x;
            tr.add(u, v, x, (op == 1) ? 1 : -1);
        } else {
            cin >> l >> y;
            cout << tr.query(u, v, l, y) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}