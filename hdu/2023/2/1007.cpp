#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1005;
const int mod = 1000000007;
bitset<N> s[N];
int n, m;

ll C_n2(ll x) {
  return 1ll * x * (x - 1) / 2 % mod;
}

ll C_n4(ll x) {
  return 1ll * x * (x - 1) * (x - 2) * (x - 3) / 24 % mod;
}

void solve() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++) s[i].reset();
  for(int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    s[u][v] = s[v][u] = 1;
  } 
  ll ans = 0;
  bitset<N> tmp1, tmp2;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(i == j) continue;
      tmp1 = s[i] & s[j];
      tmp2 = s[i] ^ tmp1;
      ll kdl1 = tmp1.count(), kdl2 = s[i].count() - 4;
      if(s[i][j] == 1) kdl2--;
      if(kdl1 >= 4 && kdl2 >= 2) {
        // cout << i << ' ' << j << endl;
        ans += 1ll * C_n2(kdl2) * C_n4(kdl1) % mod;
        ans %= mod; 
      }
    }
  }
  cout << ans % mod << endl;
}

int main(){
  freopen("1007.in", "r", stdin);
  freopen("1007.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}