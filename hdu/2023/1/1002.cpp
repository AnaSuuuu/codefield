#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 10005;
ll a[N], f[N][3], maxn, ans, tot;
struct Edge{
  int _to, _next;
} e[N << 1];
int head[N << 1];
void add_edge(int u, int v) {
  tot++;
  e[tot]._to = v;
  e[tot]._next = head[u];
  head[u] = tot;
}

void dfs(int u, int fa) {
  int chosen_son = 0;
  f[u][0] = a[u];
  f[u][1] = f[u][2] = 0;
  for(int i = head[u]; i; i = e[i]._next) {
    int v = e[i]._to;
    if(v == fa) continue;
    dfs(v, u);   
    f[u][0] += min(min(f[v][1], f[v][0]), f[v][2]);
    f[u][2] += min(f[v][1], f[v][0]);
    if(f[v][0] - min(f[v][0], f[v][1]) < f[chosen_son][0] - min(f[chosen_son][0], f[chosen_son][1])) chosen_son = v;
  }
  f[u][1] += f[chosen_son][0];
  for(int i = head[u]; i; i = e[i]._next) {
    int v = e[i]._to;
    if(v == fa || v == chosen_son) continue;
    f[u][1] += min(f[v][1], f[v][0]);
  }
  return ;
}

void solve() {
  int n;
  cin >> n;
  f[0][0] = 2147483647;
  for(int i = 1; i <= n; i++) a[i] = 1;
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    add_edge(u, v);
    add_edge(v, u);
  }
  dfs(1, 0);
  cout << min(f[1][0], f[1][1]) << endl;;/**/ 
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();
  return 0;
}