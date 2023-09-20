#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll N = 500005;

struct Edge {
  ll _to, _next;
} e[N << 1];
ll head[N], tot;
ll dfn[N], mi[21][N];
ll n, m, cnt, s;

void add_edge(ll u, ll v) {
  tot++;
  e[tot]._to = v;
  e[tot]._next = head[u];
  head[u] = tot;
}

void dfs(ll u, ll f) {
  dfn[u] = ++cnt; 
  mi[0][cnt] = f;
  for(ll i = head[u]; i; i = e[i]._next) {
    ll v = e[i]._to;
    if(v == f) continue;
    dfs(v, u);
  }
}

ll get(ll u, ll v) {
  if(dfn[u] < dfn[v]) return u;
  return v;
}

void work() {
  for(ll i = 1; i <= __lg(n); i++) {
    for(ll j = 1; j + (1 << i) - 1 <= n; j++) {
      mi[i][j] = get(mi[i - 1][j], mi[i - 1][j + (1 << (i - 1))]); 
    }
  }
}

ll LCA(ll u, ll v) {
  if(u == v) return u;
  if(dfn[v] < dfn[u]) u ^= v ^= u ^= v;
  u = dfn[u], v = dfn[v];
  // u++;
  ll k = __lg(v - u++);
  return get(mi[k][u], mi[k][v -  (1 << k) + 1]);
}

void solve() {
  cin >> n >> m >> s;
  for(ll i = 1; i < n; i++) {
    ll u, v;
    cin >> u >> v;
    add_edge(u, v);
    add_edge(v, u);
  }
  dfs(s, 0);
  work();
  while(m--) {
    int a, b;
    cin >> a >> b;
    cout << LCA(a, b) << endl;
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();
  return 0;
}