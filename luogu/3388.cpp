#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> e[N];
int dfn[N], low[N], root;
int tot, tt, vis[N];
void Tarjan(int u){
	int son = 0;
	dfn[u] = low[u] = ++tt;
	for(int v: e[u]){
		if(!dfn[v]){
			Tarjan(v); son++;
			low[u] = min(low[u], low[v]);
			if(low[v] >= dfn[u] && u != root) tot += !vis[u], vis[u] = 1; 
		}
		else low[u] = min(low[u], dfn[v]);
	}
	if(u == root && son >= 2) tot += !vis[u], vis[u] = 1;
	return ;
}
int main(){
	freopen("3388.in", "r", stdin);
	freopen("3388.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		e[v].push_back(u);
		e[u].push_back(v);
	}
	for(int i = 1; i <= n; i++) if(!dfn[i]) root = i, Tarjan(i);
	printf("%d\n", tot);
	for(int i = 1; i <= n; i++)
		if(vis[i]) printf("%d ", i);
	return 0;
}

