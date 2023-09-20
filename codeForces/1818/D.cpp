#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
vector<int> e[N];
int vis[N], dis[N];
int head[N], matrix[N][N], tot;
bool bfs(int _from, int _to){
  queue<int> q;
  memset(dis, 0x3f, sizeof(dis));
  memset(vis, 0, sizeof(vis));
  q.push(_from);
  vis[_from] = 1;
  dis[_from] = 0;
  while(q.size()){
    int u = q.front();
    q.pop();
    for(int v: e[u]){
      if(v == _to && u == _from) continue;
      if(!vis[v]) vis[v] = 1, dis[v] = dis[u] + 1, q.push(v), head[v] = u;
      if(v == _to) {
        tot = dis[v] + 3;
        return 1;
      }
    }
  }
  return 0;
}
int main(){
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--){
		int n, m;
		scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) e[i].clear();
		for(int i = 1; i <= m; i++){
			int u, v;
			scanf("%d%d", &u, &v);
			e[u].emplace_back(v);
      e[v].emplace_back(u);
		}
    int ok = 0;
    for(int u = 1; u <= n; u++){
      if(e[u].size() < 4) continue;
      //cout << u << endl;
      for(int v: e[u]){
        if(bfs(v,u)){
          //cout << u << v << endl;
          puts("YES");
          ok = 1;
          head[v] = u;
          printf("%d\n", tot);
          memset(vis, 0, sizeof(vis));
          for(int i = u; i != v; i = head[i]) printf("%d %d\n", i, head[i]), vis[i] = 1;
          printf("%d %d\n", v, u);
          vis[v] = 1;
          int cnt = 0;
          for(int i = 1; i <= n; i++){
            if(vis[i]) continue;
            if(find(e[u].begin(), e[u].end(), i) != e[u].end()) printf("%d %d\n", i, u), cnt++;
            if(cnt == 2) break;
          }
          break;
        }
      }
      if(ok) break;
    }
    if(!ok) puts("NO");
	}
	return 0;
}

