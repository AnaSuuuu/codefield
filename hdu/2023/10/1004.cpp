#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1e5 + 5;
const int mod = 998244353;
ll f[N];

inline ll qpow(ll a, ll b, ll p) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans % p * a % p;
        a = a % p * a % p;
        b >>= 1;
    }
    return ans;
}
inline ll inv(ll a, ll p) {
    return qpow(a, p - 2, p);
}

void solve() {
  int n;
  cin >> n;
  f[1] = 0; f[0] = 0;
  cout << f[1] << endl;
  for(ll i = 2; i <= n; i++) {
    for(ll j = 1; j <= i; j++) f[i] += (i - j) * (f[i - j] + 1) + (j - 1) * (f[j - 1] + 1) + 1, f[i] %= mod;
    f[i] = f[i] * inv(i * i, mod);
    f[i] = (f[i] % mod + mod) % mod;
    cout << f[i] << endl;
  }
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