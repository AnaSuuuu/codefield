#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;
ll k[N], p[N], b[N], mul[N], Inv[N], KK[N], BB[N], K_, B_; 
ll sufb[N], sufk[N], _to[N], pre[N], pos[N], ffpos[N];
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
  ll n, q, tt;
  cin >> n >> q;
  mul[0] = 1;
  for(int i = 1; i <= n; i++) {
    cin >> k[i];
  }
  for(int i = 1; i <= n; i++) cin >> b[i];
  for(int i = 1; i <= n; i++) cin >> p[i], pre[p[i]] = i;
  mul[1] = 1; Inv[1] = 1;
  KK[1] = 1, BB[1] = 0;
  KK[0] = 1, BB[0] = 0;
  for(int i = p[1]; i != 1; i = p[i]) {
    KK[i] = KK[pre[i]] * k[i] % mod;
    BB[i] = (k[i] * BB[pre[i]] % mod + b[i]) % mod;
  }
  K_ = KK[pre[1]] * k[1] % mod;
  B_ = (k[1] * BB[pre[1]] % mod + b[1]) % mod;
  pos[1] = 1; ffpos[1] = 0;
  for(int j = 2, i = p[1]; j <= n; j++, i = p[i]) {
    pos[j] = i;
    ffpos[i] = j - 1;
    mul[i] = mul[pre[i]] * k[i] % mod;
    Inv[i] = inv(mul[i], mod);
    if(j == n) tt = i;
  }
  _to[1] = 0;
  for(int i = p[1], j = 2; j <= n; j++, i = p[i]) {
    _to[i] = -b[i] * inv(k[i], mod) % mod * Inv[pre[i]] % mod + _to[pre[i]];
    _to[i] = (_to[i] % mod + mod) % mod;
  }
  // cout << _to[1] << endl;
  ll iinv = inv((K_ - 1 + mod) % mod, mod);
  while(q--) {
    ll x, l, y;
    ll K, B, End;
    cin >> x >> l >> y;
    l += ffpos[x];
    End = l % n + 1;
    K = qpow(K_, l / n, mod); 
    ll x_ = (y * Inv[x] % mod + _to[x]) % mod;
    x_ = x_ * K % mod;
    x_ = (x_ + (K - 1) * iinv % mod * B_ % mod + mod) % mod; 
    // cout << End << "AAA" << endl;
    ll ans = (x_ * KK[pos[End]]  % mod + BB[pos[End]]) % mod; 
    cout << (ans + mod) % mod << endl;
  }
}

int main(){
  freopen("1010.in", "r", stdin);
  freopen("1010.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}