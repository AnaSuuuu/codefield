#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 505;
const int mod = 998244353;

int n, m, tot, head[N];
struct Edge{
  int _to, _next, _dis;
} e[N * N];

void add_edge(int u, int v, int w) {
  tot++;
  e[tot]._next = head[u];
  e[tot]._to = v;
  e[tot]._dis = w;
  head[u] = tot;
}

void solve() {
  cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    add_edge(u, v, w);
  }
  for(int i = 1; i <= n; i++) {
    
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    solve();
  } 
  return 0;
}