#include<bits/stdc++.h> 

const int  N = 2e5 + 5; 
std::vector<std::pair<int, int>>e[N];
int tot, ans[N];

int dfs(int u, int fa) {
  int cnt1 = 0, cnt2 = 0;
  //std::cout << u << ' ' << fa << "\n";
  for(auto &it: e[u]) {
    int v = it.first, id = it.second;
    if(v == fa) continue;
    int kdl = dfs(v, u);
    if(kdl == -1) {
      return -1;
    }
    if(kdl == 1) cnt1++;
    if(kdl == 2) cnt2++;
    if(kdl == 0) ans[++tot] = id;
  }
  if(cnt1 && cnt2) return -1;
  if(cnt2 > 1) return -1;
  if(cnt1 > 2) return -1;
  if(cnt2 == 1 || cnt1 == 2) return 0;
  if(cnt1 == 1) return 2;
  return 1;
}

void solve() {
  int n;
  std::cin >> n;
  //std::cout << n << "\n";
  for(int i = 1; i <= n; i++) e[i].clear();
  for(int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    e[u].emplace_back(v, i);
    e[v].emplace_back(u, i);
  }
  //std::cout << n << ' ' << n % 3 << std::endl;
  //std::cout << "AAA" << std::endl;
  if(n % 3) {
    std::cout << "-1\n";
    return ;
  }
  tot = 0;
  //puts("CCC");
  if(dfs(1, 0) != 0) {
    std::cout << "-1\n";
    return ;
  }
  std::cout << tot << "\n";
  if(tot == 0) std::cout << "\n";
  for(int i = 1; i <= tot; i++) 
    std::cout << ans[i] << " \n"[i == tot];
  return ;
}

int main() {
  //freopen("D.in", "r", stdin);
  //freopen("D.out", "w", stdout);

  std::ios::sync_with_stdio(0);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}