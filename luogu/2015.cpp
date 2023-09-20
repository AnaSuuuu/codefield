#include<bits/stdc++.h>
using namespace std;
const int N = 105;
struct Edge{
  int dis, _to;
};
int son[N], f[N][N];
int n, q, ans;
vector<Edge> e[N];
void dfs(int u, int fa){
  son[u] = 0;
  for(Edge tmp: e[u]){
    int v = tmp._to;
    if(v == fa) continue;
    int num = tmp.dis;
    dfs(v, u);
    son[u] += son[v] + 1;
    for(int i = q; i >= 1; i--){
      for(int j = 0; j <= min(son[u], i - 1); j++) 
        f[u][i] = max(f[u][i], f[u][i - j - 1] + f[v][j] + num);
    }
  }
}
int main(){
  freopen("2015.in", "r", stdin);
  freopen("2015.out", "w", stdout);
  cin >> n >> q;
  for(int i = 1; i < n; i++){
    int u, v, w;
    cin >> u >> v >>w;
    e[u].emplace_back((Edge){w, v});
    e[v].emplace_back((Edge){w, u});
  }
  dfs(1, 0);
  //for(int i = 1; i <= n; i++) cout << f[i][2] << ' ';
  //cout << endl;
  cout << f[1][q] << endl;
  return 0;
}