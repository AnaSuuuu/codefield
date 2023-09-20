#include <bits/stdc++.h>

const int N = 1005;
const int zh[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int a[N][N], vis[N][N];
int n, m, ans, tmp;

void dfs(int x, int y) {
  for(int i = 0; i < 4; i++) {
    int dx = x + zh[i][0], dy = y + zh[i][1];
    if(dx > n || dx < 1 || dy > m || dy < 1) continue;
    if(vis[dx][dy]) continue;
    tmp += a[dx][dy], vis[dx][dy] = 1;
    dfs(dx, dy);
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while(t--) {
    ans = 0, tmp = 0;
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) 
      for(int j = 1; j <= m; j++)
        std::cin >> a[i][j], vis[i][j] = (a[i][j] == 0);
    //for(int i = 1; i <= n; i++) 
    //  for(int j = 1; j <= m; j++) std::cout << vis[i][j] <<" \n"[j == m];    
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        if(vis[i][j] == 0) tmp = a[i][j], vis[i][j] = 1, dfs(i, j);
        ans = std::max(ans, tmp);
      }
    }
    std::cout << ans << "\n";
  }
}