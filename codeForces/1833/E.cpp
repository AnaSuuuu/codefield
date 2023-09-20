#include<bits/stdc++.h>

const int N = 2e5 + 5;
int a[N], vis[N];
std::vector<int> e[N];

void dfs(int u, int fa) {
  if(vis[u]) return ;
  vis[u] = 1;
  for(int v: e[u]) {
    if(v == fa) continue;
    dfs(v, fa);
  }
  return ;
}

void solve() {
  int n;
  int cnt_cy = 0, cnt_lin = 0;
  std::cin >> n;
  for(int i = 1; i <= n; i++) e[i].clear();
  for(int i = 1; i <= n; i++) {
    std::cin >> a[i];
    e[i].emplace_back(a[i]);
    e[a[i]].emplace_back(i);
  }
  for(int i = 1; i <= n; i++) {
    if(vis[i]) continue;
    //vis[i] = 1;
    dfs(a[i], i);
    if(vis[a[i]]) cnt_cy++;
    else cnt_lin++;
  }
  std::cout << cnt_cy + std::min(cnt_cy, 1) << ' ' << cnt_cy + cnt_lin << std::endl;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}