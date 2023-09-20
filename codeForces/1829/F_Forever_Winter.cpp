#include <bits/stdc++.h>

const int N = 205;
int du[N];
std::vector<int> e[N];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while(t--) {
    std::memset(du, 0, sizeof(du));
    int n, m;
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) e[i].clear();
    for(int i = 1; i <= m; i++) {
      int x, y;
      std::cin >> x >> y;
      du[x]++;
      du[y]++;
      e[x].emplace_back(y);
      e[y].emplace_back(x);
    }
    int ans1, ans2;
    for(int i = 1; i <= n; i++) {
      if(du[i] == 1) {
        ans1 = e[e[i].front()].size() - 1;
        for(auto v: e[e[i].front()]) {
          if(e[v].size() != 1) {
            ans2 = e[v].size();
            break;
          }
        }
        break;
      }
    }
    std::cout << ans2 << ' ' << ans1 << "\n";
  }
}