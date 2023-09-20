#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int mod = 998244353;

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
const int N = 1e6 + 5;
ll Inv[N];
void work() {
  Inv[1] = 1;
  for (ll i = 2; i <= 1e6; ++i) {
    Inv[i] = (ll)(mod - mod / i) * Inv[mod % i] % mod;
  }
}
void solve() {
  ll n, m, a, b, tmp, ans = 0, kk, C, xs, gjr;
  cin >> n >> m >> b >> a;
  tmp = qpow(a, n, mod); 
  kk = qpow(inv(a, mod), n, mod); 
  C = 1;
  gjr = inv(a - b, mod);
  xs = qpow(a - b, n, mod);
  for(ll i = 1; i <= n; i++) {
    ll kdl = qpow(i, m, mod);
    ans = (ans + (tmp - C * xs % mod) % mod * kdl % mod) % mod;
    tmp -= C * xs % mod;
    tmp = (tmp % mod + mod) % mod;
    C = C * (n - i + 1) % mod * Inv[i] % mod;
    xs = xs * b % mod * gjr % mod;
  }
  cout << (ans * kk % mod + mod) % mod << endl;
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  work();
  while(t--) {
    solve();
  }
  return 0;
}