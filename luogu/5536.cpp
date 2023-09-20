#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> e[N];
int deep[N], maxn, id, fa[N];
int deepn[N], max_deep[N];
int kdl[N];
void dfs(int u,int f){
  fa[u] = f;
  for(int v:e[u]){
    if(v == f) continue;
    deep[v] = deep[u] + 1;
    dfs(v, u);
    if(maxn < deep[v]) {
      maxn = deep[v];
      id = v;
    }
  }
} 
void dfs1(int u, int f){
  max_deep[u] = deepn[u];
  for(int v: e[u]){
    if(v == f) continue;
    deepn[v] = deepn[u] + 1;
    dfs1(v, u);
    max_deep[u] = max(max_deep[u], max_deep[v]);
  }
}
bool cmp(int &x, int &y){
  return x > y;
}
int main(){
	freopen("5536.in", "r", stdin);
	freopen("5536.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
  deep[1] = 1;
	dfs(1, 0);
  //cout << id << endl;
  maxn = 0;
  deep[id] = 1;
  dfs(id, 0);
  //cout << id << endl;
  //cout << maxn << endl;
  int root = id;
  for(int i = 1; i <= maxn / 2; i++) root = fa[root];
  //cout << root << endl;
  deepn[root] = 1;
  dfs1(root, 0);
  for(int i = 1; i <= n; i++) kdl[i] = max_deep[i] - deepn[i];
  //for(int i = 1; i <= n; i++) cout << deepn[i] << ' ';
  //cout << endl;
  //for(int i = 1; i <= n; i++) cout << max_deep[i] << ' ';
  sort(kdl + 1, kdl + 1 + n, cmp);
  int ans = 0;
  for(int i = k + 1; i <= n; i++) ans = max(ans, kdl[i]);
  cout << ans + 1 << endl;
  return 0;
}

