#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


const int N = 1e6 + 5;
int fa[N], F[N], S[N], vis[N], dis[N];
int head[N], tot, ans;
struct edge{
  int _to, _next;
} e[N];
int f(int x) {
  return (fa[x] == x ? x : fa[x] = f(fa[x]));
}
void add_edge(int u, int v) {
  tot++;
  e[tot]._to = v;
  e[tot]._next = head[u];
  head[u] = tot;
}
ll cal(ll x) {
  ll tmp = 1, cnt = 1;
  while(tmp < x) {
    tmp <<= 1;
    cnt++;
  }
  return cnt;
}
void dfs(int u, int ff, int tmp) {
  ans = max(ans, tmp);
  for(int i = head[u]; i; i = e[i]._next) {
    int v = e[i]._to;
    if(v == ff) continue;
    dfs(v, u, tmp + dis[v]);
  }
}
void solve() {
  ll n;
  ans = 0;
  cin >> n;
  for(int i = 1; i <= n; i++) fa[i] = i, vis[i] = 0, head[i] = 0;
  for(int i = 1; i <= n; i++) cin >> F[i];
  for(int i = 1; i <= n; i++) cin >> S[i];
  for(int i = 1; i <= n; i++) {
    int tmp = i;
    if(vis[i]) continue;
    vis[i] = dis[i] = 1;
    while(S[tmp] != 0) {
      vis[tmp] = 1;
      fa[S[tmp]] = i;
      tmp = S[tmp];
      dis[i]++;
    }
    dis[i] = cal(dis[i]);
    fa[tmp] = i, vis[tmp] = 1;
  }
  for(int i = 1; i <= n; i++) fa[i] = f(fa[i]), dis[i] = dis[fa[i]];
  tot = 0;
  for(int i = 1; i <= n; i++) {
    if(F[i] == 0) continue;
    if(f(F[i]) == f(i)) continue;
    add_edge(f(F[i]), f(i));
  }
  /* for(int i = 1; i <= n; i++) cout << fa[i] << ' ';
  cout << endl;
  for(int i = 1; i <= n; i++) cout << dis[i] << ' ';
  cout << endl;*/
  dfs(1, 0, dis[1]);
  cout << ans << endl;
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int size(512<<20); // 512M
  __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size)); // YOUR CODE

  int t;
  cin >> t;
  while(t--) {
    solve();
  } 
  exit(0);
  return 0;
}