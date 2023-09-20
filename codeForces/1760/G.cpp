#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 4e5+5;
int head[N], tot;
ll dis[N];
int n, a, b;
bool ok;
map<ll ,int> q;
struct Edge{
  int _to, _next;
  ll  _weight;
} e[N];
void add_edge (int u, int v, int w){
  tot++;
  e[tot]._next = head[u];
  e[tot]._to = v;
  e[tot]._weight = w;
  head[u] = tot;
}
void dfs1(int u, int fa){
  for(int i = head[u]; i; i = e[i]._next){
    int v = e[i]._to;
    if(v == fa || v == b) continue;
    dis[v] = dis[u] ^ e[i]._weight;
    q[dis[v]] = 1;
    dfs1(v, u);
  }
}
void dfs2(int u,int fa){
  if(ok) return ;
  for(int i = head[u]; i; i = e[i]._next){
    int v = e[i]._to;
    if(v == fa)continue;
    dis[v] = dis[u] ^ e[i]._weight;
    if(q[dis[v]]){
      ok = 1;
      return ;
    }
    dfs2(v,u);
  }
}
int main(){
  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);
  int t;
  cin >> t;
  while(t--){
    tot = 0;
    ok = 0;
    q.clear();
    cin >> n >> a >> b;
    memset(head, 0, sizeof(head));
    for(int i = 1; i < n; i++){
      int u, v, w;
      cin >> u >> v >> w;
      add_edge(u, v, w);
      add_edge(v, u, w);
    }
    q[0] = 1;
    dis[a] = 0;
    dfs1(a, 0);
    dis[b] = 0;
    dfs2(b, 0);
    if(ok) puts("YES");
    else puts("NO");
  }
}
