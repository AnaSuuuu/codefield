#include <bits/stdc++.h>
typedef long long ll;

const int N = 1e6 + 6;
ll a[N];

void solve() {
  ll k, n, m, x;
  ll sum = 0, ans = 0;
  std::cin >> k;
  for(int i = 0; i < k; i++) std::cin >> a[i];
  std::cin >> n >> m >> x;
  x %= m;
  for(int i = 0; i < k; i++) a[i] %= m, sum += a[i], ans += (a[i] == 0);
  sum *= (n / k); ans *= (n / k);
  //std::cout << x << "\n";
  //for(int i = 0; i < k; i++) std::cout << a[i] << " \n"[i == k - 1];
  //std::cout << ans << std::endl;
  for(int i = 1; i <= n % k; i++) sum += a[i - 1], ans += (a[i - 1] == 0);
  sum += x;
  //std::cout << sum << ' ' << ans << "\n";
  std::cout << n - sum / m + ans << "\n";
}

int main() {
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