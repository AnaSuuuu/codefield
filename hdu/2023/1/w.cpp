#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <functional>

using namespace std;

using i64 = long long;

const int N = 3010;
const i64 inf = 1e18;

int ts, st[N * 2][22], lg[2 * N], first[N];
int dep[N], n, m;
vector<int> adj[N];

void dfs(int u, int fa) {
  dep[u] = dep[fa] + 1;
  st[++ts][0] = u, first[u] = ts;
  for (auto v : adj[u]) {
    if (v == fa) continue;
    dfs(v, u);  
    st[++ts][0] = u;
  }
}
 
int mind(int x, int y) {
  return dep[x] < dep[y] ? x : y;
}
 
int lca(int u, int v) {
  int l = first[u], r = first[v]; 
  if (l > r) swap(l, r);
  int k = lg[r - l + 1];
  return mind(st[l][k], st[r - (1 << k) + 1][k]); 
}

void init() {
  ts = 0;
  dfs(1, 0);
  lg[1] = 0;
  for (int i = 2; i <= ts; i++) lg[i] = lg[i >> 1] + 1;
  for (int j = 1; j < 13; j++)
    for (int i = 1; i + (1 << j) - 1 <= ts; i++)
      st[i][j] = mind(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
}

int dist(int u, int v) {
  int p = lca(u, v);
  return dep[u] + dep[v] - 2 * dep[p];
}

bool on(int i, int u, int v) {
  return dist(i, u) + dist(i, v) == dist(u, v);  
}

int exgcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  int d = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

int main() {
  freopen("1001.in", "r", stdin);
  freopen("w.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      vector<int>().swap(adj[i]);
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }
    init();
    while (m--) {
      int u1, v1, u2, v2;
      cin >> u1 >> v1 >> u2 >> v2;
      int a = 2 * dist(u1, v1), b = 2 * dist(u2, v2), d = __gcd(a, b);
      i64 res = inf;
      int pos = -1;
      function<i64(int, int)> calc = [&](int p, int q) {
        int c = ((q - p) % b + b) % b;
        if (c % d) return inf;
        int x, y;
        exgcd(a, b, x, y);
        int mod = b / d;
        x = x * c / d;
        if (mod < 0) mod = -mod;
        x = (x % mod + mod) % mod;
        return 1ll * x * a + p;
      };
      for (int i = 1; i <= n; i++) {
        if (!on(i, u1, v1) || !on(i, u2, v2)) continue;
        vector<int> v1, v2;
        v1.emplace_back(dist(i, u1));
        v1.emplace_back(a - dist(i, u1));
        v2.emplace_back(dist(i, u2));
        v2.emplace_back(b - dist(i, u2));
        for (auto p : v1) {
          for (auto q : v2) {
            i64 tmp = calc(p, q);
            if (tmp < res) {
              res = tmp;
              pos = i;
            }
          }
        }
      }    
      cout << pos << '\n';
    }
  }
  return 0;
}