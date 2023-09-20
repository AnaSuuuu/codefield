#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 305;
struct Edge{
  int _to, _next;
} e[N];
int head[N], tot;
int f[10005][105], hh[105], kdl[105];

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  hh[0] = 0;
  for(int i = 1; i <= k; i++) {
    int u, v;
    cin >> u >> v;
    if(v == m) hh[++hh[0]] = u;
  }
  int val[5];
  val[0] = val[1] = val[2] = 0;
  for(int i = 1; i <= n; i++) 
    for(int j = 1; j <= m; j++) cin >> f[i][j];
  for(int i = 1; i < m; i++) cin >> kdl[i];
  for(int i = 1; i <= n; i++) {
    int ok = 1;
    for(int j = 1; j <= hh[0]; j++) {
      if(kdl[hh[j]] != f[i][hh[j]]) {
        ok = 0;
        break;
      }
    }
    if(ok == 1) val[f[i][m]]++;
  }
  if(val[2] > val[1] && val[2] > val[0]) cout << 2 << endl;
  else if(val[1] > val[2] && val[1] > val[0]) cout << 1 << endl;
        else cout << 0 << endl;
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