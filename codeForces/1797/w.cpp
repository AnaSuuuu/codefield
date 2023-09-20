//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5 + 5, P = 4e5 + 5, K = 5e6 + 5, W = 5e6; 
 
int n, m, a[N], tab[K], phi[K], p[P], pcnt, dis[K], fa[K][6];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void sieve(int lim) {
	phi[1] = 1;
	rep(i, 2, lim) {
		if(!tab[i]) {
			p[++pcnt] = i;
			phi[i] = i - 1;
		}
		for(int j=1;j<=pcnt&&1LL*i*p[j]<=lim;j++) {
			tab[i*p[j]] = 1;
			if(i % p[j]) phi[i*p[j]] = phi[i] * phi[p[j]];
			else {
				phi[i*p[j]] = phi[i] * p[j];
				break;
			}
		}
	}
}
void initTree(int lim) {
	dis[1] = 1;
	rep(j, 0, 5) fa[1][j] = 1;
	rep(i, 2, lim) {
		dis[i] = dis[phi[i]] + 1;
		fa[i][0] = phi[i];
		rep(j, 1, 5) fa[i][j] = fa[fa[i][j-1]][j-1];
	}
}
int LCA(int u, int v) {
	if(dis[u] < dis[v]) swap(u, v);
	per(i, 5, 0) if(dis[fa[u][i]] >= dis[v]) u = fa[u][i];
	if(u == v) return u;
	per(i, 5, 0) if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
struct Node {
	int lca, ans, mndis, allrt;
};
struct SegTree {
	Node t[N<<2];
	#define lc(u) (u<<1)
	#define rc(u) (u<<1|1)
	void pushup(int u, int l, int r) {
		int mid = (l + r) >> 1;
		t[u].lca = LCA(t[lc(u)].lca, t[rc(u)].lca);
		t[u].ans = t[lc(u)].ans + t[rc(u)].ans
				 + (mid - l + 1) * (dis[t[lc(u)].lca] - dis[t[u].lca])
				 + (r - mid) * (dis[t[rc(u)].lca] - dis[t[u].lca]);
		t[u].mndis = min(t[lc(u)].mndis, t[rc(u)].mndis);
		t[u].allrt = t[lc(u)].allrt && t[rc(u)].allrt;
	}
	void build(int u, int l, int r) {
		if(l == r) {
			t[u].lca = a[l];
			t[u].ans = 0;
			t[u].mndis = dis[a[l]];
			t[u].allrt = a[l] == 1;
			return;
		}
		int mid = (l + r) >> 1;
		build(lc(u), l, mid);
		build(rc(u), mid+1, r);
		pushup(u, l, r);
	}
	void modify(int u, int l, int r, int ql, int qr) {
		if(t[u].allrt) return;
		if(l == r) {
			t[u].lca = fa[t[u].lca][0];
			--t[u].mndis;
			t[u].allrt = t[u].lca == 1;
			return;
		}
		int mid = (l + r) >> 1;
		if(ql <= mid) modify(lc(u), l, mid, ql, qr);
		if(qr > mid) modify(rc(u), mid+1, r, ql, qr);
		pushup(u, l, r);
	}
	int queryLCA(int u, int l, int r, int ql, int qr) {
		if(ql <= l && r <= qr) return t[u].lca;
		int mid = (l + r) >> 1;
		if(qr <= mid) return queryLCA(lc(u), l, mid, ql, qr);
		if(ql > mid) return queryLCA(rc(u), mid+1, r, ql, qr);
		int ans = queryLCA(lc(u), l, mid, ql, qr);
		if(ans == 1) return 1;
		return LCA(ans, queryLCA(rc(u), mid+1, r, ql, qr));
	}
	int queryAns(int u, int l, int r, int ql, int qr, int lca) {
		if(ql <= l && r <= qr) {
			return t[u].ans + (r - l + 1) * (dis[t[u].lca] - dis[lca]);
		}
		int mid = (l + r) >> 1, ans = 0;
		if(ql <= mid) ans += queryAns(lc(u), l, mid, ql, qr, lca);
		if(qr > mid) ans += queryAns(rc(u), mid+1, r, ql, qr, lca);
		return ans;
	}
	#undef lc
	#undef rc
}sgt;
 
int main() {
  freopen("E.in", "r", stdin);
  freopen("w.out", "w", stdout);
	sieve(W);
	initTree(W);
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", &a[i]);
	sgt.build(1, 1, n);
	while(m --> 0) {
		int op, l, r;
		scanf("%d%d%d", &op, &l, &r);
		if(op == 1) sgt.modify(1, 1, n, l, r);
		else {
			int lca = sgt.queryLCA(1, 1, n, l, r);
			printf("%d\n", sgt.queryAns(1, 1, n, l, r, lca));
		}
	}
	return 0;
}