#include <bits/stdc++.h>
typedef long long ll;

const int N = 1e6 + 6;
std::vector<int> e[N];
int ans[N];

void solve() {
  ll n, p, tmp = 0;
  std::cin >> n >> p;
  if(p == 1) {
    for(int i = 1; i <= n; i++) {
      int x;
      std::cin >> x;
      tmp += x % 2;
      tmp %= 2;
    }
    std::cout << (tmp ? "GOOD" : "BAD") << "\n";
    return ;
  }
  for(int i = 1; i <= n; i++) {
    ll x;
    std::cin >> x;
    while(x) {
      tmp += x % p;
      tmp %= 2;
      x /= p;
    }
  }
  std::cout << (tmp ? "GOOD" : "BAD") << "\n";
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