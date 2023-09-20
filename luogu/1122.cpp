#include<bits/stdc++.h>
using namespace std;
const int N = 16005;
int a[N], sum[N], ans;
vector<int> e[N];
void dfs(int u, int f){
  sum[u] = a[u];
  for(int v: e[u]){
    if(v == f) continue;
    dfs(v, u);
    sum[u] += max(0, sum[v]);
  }
  ans = max(ans, sum[u]);
}
int main(){
  freopen("1122.in", "r", stdin);
  freopen("1122.out", "w", stdout);
  int n;
  cin >> n;
  int maxn = -2147483648;
  for(int i = 1; i <= n; i++) cin >> a[i], maxn = max(maxn, a[i]); 
  for(int i = 1; i < n; i++){
    int u, v;
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  if(maxn < 0) cout << maxn << endl;
  else{
    dfs(1, 0);
    cout << ans << endl;
  }
  return 0;
}