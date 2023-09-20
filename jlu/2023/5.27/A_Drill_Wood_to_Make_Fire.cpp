#include <bits/stdc++.h>

void solve() {
  int n, s, v;
  std::cin >> n >> s >> v;
  std::cout << (s * v >= n ? 1 : 0) << "\n";
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}