#include<bits/stdc++.h>
using namespace std;
const int N = 6e3 +5;
int r[N], deg[N], f[N][2];
vector<int> e[N];
int ans;
void dfs(int u){
  f[u][1] = r[u];
	for(int v: e[u]){
		dfs(v);
		f[u][0] += max(f[v][1], f[v][0]);
		f[u][1] += f[v][0];
	}
	ans = max(ans, max(f[u][1], f[u][0]));
}
int main(){
	freopen("1352.in", "r", stdin);
	freopen("1352.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> r[i];
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> v >> u;
		e[u].emplace_back(v); deg[v]++;
	}
	for(int i = 1; i <= n; i++) if(deg[i] == 0) dfs(i);//, cout << i << "AAA" << endl;
  //for(int i = 1; i <= n; i++) cout << f[i][0] << ' ' << f[i][1] << endl;
	cout << ans << endl;
	return 0;
}

