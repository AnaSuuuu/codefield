#include <bits/stdc++.h>
typedef long long ll;

const int N = 1e6 + 6;
ll a[N], b[N];

void solve() {
  ll k, n, m, x;
  ll sum = 0, ans = 0;
  std::cin >> k;
  for(int i = 0; i < k; i++) std::cin >> a[i];
  std::cin >> n >> m >> x;
  x %= m;
  for(int i = 0; i < k; i++) a[i] %= m;
  b[0] = x;
  for(int i = 1; i <= n; i++) {
    b[i] = b[i - 1] + a[(i - 1) % k];
    b[i] %= m;
    if(b[i] >= b[i - 1]) ans++;
  }
  std::cout << ans << "\n";
}

int main() {
  freopen("w.out", "r", stdin);
  freopen("w0.out", "w", stdout);

  std::ios::sync_with_stdio(0);
  std::cin.tie(nullptr);

  bool multi_test = 0;
  int t = 1;
  if(multi_test) std::cin >> t;

  while(t--) {
    solve();
  }

  return 0;
}