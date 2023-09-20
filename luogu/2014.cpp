#include<bits/stdc++.h>
using namespace std;
const int N = 305;
int s[N], deg[N];
vector<int> e[N];
int n, m, f[N][N], dp[N];
int son[N];
void dfs(int u){
  f[u][1] = s[u];
  son[u] = 1;
  for(int v: e[u]){
    dfs(v);
    son[u] += son[v];
    for(int i = m; i >= 1; i--){
      for(int j = 0; j <= min(i - 1, son[v]); j++)
        f[u][i] = max(f[u][i], f[v][j] + f[u][i - j]);
    }
  }
}
int main(){
  freopen("2014.in", "r", stdin);
  freopen("2014.out", "w", stdout);
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    int v;
    cin >> v >> s[i];
    if(v != 0) {
      e[v].emplace_back(i);
      deg[i]++;
    } 
  }
  for(int i = 1; i <= n; i++){
    if(deg[i] != 0) continue;
    if(deg[i] == 0) dfs(i);
    for(int j = m; j >= 1; j--){
      for(int k = 0; k <= j; k++) dp[j] = max(dp[j], dp[j - k] + f[i][k]);
    }
    //cout << f[i][m] << endl;
  }
  //cout << f[7][2] << endl;
  cout << dp[m] << endl;
  return 0;
}