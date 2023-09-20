#include <bits/stdc++.h>
typedef long long ll;

const int N = 1e6 + 6;
std::vector<int> e[N];
int ans[N];

void solve() {
  int n, q;
  std::cin >> n >> q;
  for(int i = 1; i < n; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    ans[x] ^= w;
    ans[y] ^= w;
  }
  while(q--) {
    int op;
    std::cin >> op;
    switch(op) {
      case 1: {
        int u, v, w;
        std::cin >> u >> v >> w;
        ans[u] ^= w;
        ans[v] ^= w;
        break;
      }
      case 2:{
        int x;
        std::cin >> x;
        std::cout << ans[x] << "\n";
        break;
      }
    }
  }
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