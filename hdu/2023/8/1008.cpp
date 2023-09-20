#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int mod = 1e9 + 7;

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
  ll n, p, P = 0, Q, tmp, kdl, hh;
  cin >> n >> p;
  tmp = qpow(p, n, mod) - 1;
  kdl = 2;
  if(n & 1) hh = 1;
  else hh = qpow(2, n, mod);
  Q = qpow(inv(p, mod), n * n, mod);
  for(ll i = 1; i <= n; i++) {
    P = (P + tmp * qpow(kdl, n - i, mod) % mod * i) % mod;
    tmp = tmp * (qpow(p, n, mod) - 2 * i + 1) % mod;
    kdl <<= 1;
    kdl %= mod;
    cout << P << endl;
  }
  // cout << P << endl;
  cout << P * inv(Q, mod) % mod << endl;
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    solve();
    cout << (1ll * 802469143 * 81 % mod) << endl;
  } 
  return 0;
}