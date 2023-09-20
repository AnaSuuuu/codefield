#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
 
const ll mod = 998244353;
const int N = 2e5 + 5;
ll f[N], Pow[N];
 
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
 
 
int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ll n, k, ans = 0;
  cin >> n >> k;
  Pow[0] = 1;
  for(ll i = 1; i <= n; i++) Pow[i] = 1ll * Pow[i - 1] * i % mod;
  if(n > k) {
    for(ll i = 1; i <= k; i++) 
      ans = (ans + (qpow(i + 1, k + 1 - i, mod) - qpow(i, k - i + 1, mod) + mod) % mod * Pow[i] % mod * Pow[n] % mod * inv(Pow[n - i], mod) % mod) % mod;
  }
  else {
    for(ll i = 1; i <= n; i++) 
      ans = (ans + (qpow(i + 1, k + 1 - i, mod) - qpow(i, k - i + 1, mod) + mod) % mod * Pow[i] % mod * Pow[n] % mod * inv(Pow[n - i], mod) % mod) % mod;//, cout << ans << endl;;
  }
  cout << (ans + 1) % mod << endl;
  return 0;
}