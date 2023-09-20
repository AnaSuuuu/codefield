#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

constexpr int mod = 998244353;
void addt(int &x, int y) {x += y, x >= mod && (x -= mod);}
int add(int x, int y) {return x += y, x >= mod && (x -= mod), x;}
int ksm(int a, int b) {
  int s = 1;
  while(b) {
    if(b & 1) s = 1ll * s * a % mod;
    a = 1ll * a * a % mod, b >>= 1;
  }
  return s;
}

bool Mbe;
constexpr int N = 1e6 + 5;

int n, r[N], f[N], g[N], pre[N], nxt[N];
char s[N], t[N];
void solve() {
  cin >> n >> s + 1;
  int m = 1;
  t[0] = '#', t[1] = '!';
  for(int i = 1; i <= n; i++) {
    t[++m] = s[i], t[++m] = '!';
    f[i] = 0, pre[i] = i - 1, nxt[i] = i + 1;
  }
  t[++m] = '?';
  for(int i = 1, d = 0, rt = 0; i < m; i += 2) {
    r[i] = i > rt ? 1 : min(r[d * 2 - i], rt - i + 1);
    while(t[i + r[i]] == t[i - r[i]]) r[i]++;
    if(i + r[i] - 1 > rt) d = i, rt = i + r[i] - 1;
  }
  for(int i = m - 1; i > 0; i -= 2) {
    int l = i + 1 >> 1, lim = i + r[i] - 2 >> 1;
    for(int p = l; p <= lim; p = nxt[p]) {
      f[p] = p * 2 - i + 1;
      nxt[pre[p]] = nxt[p];
      pre[nxt[p]] = pre[p];
    }
  }
  ll ans = 0;
  for(int i = 1; i <= n; i++) {
    if(f[i]) g[i] = 1 + g[i - f[i]];
    else g[i] = 0;
    ans += g[i];
  }
  for(int i = 1; i <= m; i++) cout << t[i] << ' ';
  cout << endl;
  for(int i = 1; i <= m; i++) cout << r[i] << ' ';
  cout << endl;
  cout << ans << "\n";
}

bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T = 1;
  cin >> T;
  while(T--) solve();
  cerr << 1e3 * clock() / CLOCKS_PER_SEC << " ms\n";
  return 0;
}