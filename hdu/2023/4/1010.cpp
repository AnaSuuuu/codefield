#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 70;
const int zh[4][2] = {{2, 0}, {-2, 0}, {0, 2}, {0, -2}};
int ans, n, m;
int vis[N][N];
void dfs(int tmp) {
  if(tmp < ans) {
    ans = tmp;
    /*if(tmp == 1) {
      for(int i = 1; i <= n + 2; i++) {
        for(int j = 1; j <= m + 2; j++) cout << vis[i][j];
       cout << endl;
      }
     cout << endl;
    }*/
  }
  for(int i = 1; i <= n + 2; i++) {
    for(int j = 1; j <= m + 2; j++) {
      for(int k = 0; k < 4; k++) {
        int dx = i + zh[k][0], dy = j + zh[k][1];
        if(dx < 1 || dx > n + 2 || dy < 1 || dy > m + 2) continue;
        if(vis[i][j] == 1 && vis[dx][dy] == 0 && vis[i + dx >> 1][j + dy >> 1] == 1) {
         /*  if(tmp == 2) {
      for(int _ = 1; _ <= n + 2; _++) {
        for(int O = 1; O <= m + 2; O++) cout << vis[_][O];
       cout << endl;
      }
     cout << endl;
    }*/
          vis[i][j] = 0;
          vis[i + dx >> 1][j + dy >> 1] = 0;
          vis[dx][dy] = 1;
         
          dfs(tmp - 1);
          vis[i][j] = 1;
          vis[i + dx >> 1][j + dy >> 1] = 1;
          vis[dx][dy] = 0;
        }
      }
    }
  }  
}

void solve() {
  cin >> n >> m;
  ans = n * m;
  // cout << ans << "AA\n";
  memset(vis, 0, sizeof(vis));
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++)
      vis[i + 1][j + 1] = 1;
  }
  dfs(n * m);
  cout << ans << endl;
  return ;
}

int main(){
  freopen("1010.in", "r", stdin);
  freopen("1010.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    solve();    
  } 
  return 0;
}