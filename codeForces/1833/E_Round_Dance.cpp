#include<bits/stdc++.h>

const int N = 2e5 + 5;
int a[N], vis[N];
std::vector<int> e[N];

void dfs(int u, int fa) {
  vis[u]++;
  if(vis[u] == 2) return ;
  for(int v: e[u]) {
    if(v == fa) continue;
    dfs(v, u);
  }
  return ;
}

void solve() {
  int n;
  int cnt_cy = 0, cnt_lin = 0;
  std::cin >> n;
  std::memset(vis, 0, sizeof(vis));
  for(int i = 1; i <= n; i++) e[i].clear();
  for(int i = 1; i <= n; i++) {
    std::cin >> a[i];
    e[i].emplace_back(a[i]);
    e[a[i]].emplace_back(i);
  }
  for(int i = 1; i <= n; i++) {
    if(vis[i]) continue;
    //vis[i] = 1;
    dfs(i, 0);
    if(vis[i] == 2) cnt_cy++;
    else cnt_lin++;
    //std::cout << i << ' ' << vis[i] << std::endl;
    vis[i] = 1;
  }
  //std::cout << cnt_cy << ' ' << cnt_lin << std::endl;
  std::cout << cnt_cy + std::min(cnt_lin, 1) << ' ' << cnt_cy + cnt_lin << std::endl;
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