#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll mod = 998244353;
const int N = 5e5 + 5;
ll n, m, a[N], b[N], sum, cnt;

void dfs(ll tmp) {
  if(tmp == 2 * n + 1) {
    cnt++;
    for(int i = 1; i <= n; i++) a[i] = i;
    for(int i = 1; i <= n * 2; i += 2) {
      int x = a[b[i]], y = a[b[i + 1]];
      a[b[i + 1]] = x, a[b[i]] = y;
    }
    for(int i = 1; i <= n; i++) sum += (a[i] != i);
    return ;
  } 
  for(int i = 1; i <= n; i++) {
    b[tmp] = i;
    dfs(tmp + 1);
  }
  return ;
}

void solve() {
  cin >> n >> m;
  if(n == 1) {
    cout << 0 << endl;
    return ;
  }
  sum = 0; cnt = 0;
  dfs(1);
  cout << (double)sum / cnt << endl;/* */
}

int main(){
  freopen("1004.in", "r", stdin);
  freopen("1004.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    solve();
  } 
  return 0;
}