#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 5e6 + 5;
int a[N], s[N], sInv[N], Inv[N];
int n, p, k;

inline void in(int & x) {
  x = 0;
  int f = 1;
  char c = getchar();
  while(c > '9' || c < '0') {
    if(c == '-') f = -1;
    c = getchar();
  }
  while(c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - '0', c = getchar();
  x *= f;
} 

void init() {
  in(n), in(p), in(k);
  for(int i = 1; i <= n; i++) in(a[i]);
}

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
  s[1] = a[1];
  for(int i = 2; i <= n; i++) {
    s[i] = 1ll * s[i - 1] * a[i] % p;
  }
  sInv[n] = inv(s[n], p);
  for(int i = n - 1; i >= 1; i--) sInv[i] = (1ll * sInv[i + 1] * a[i + 1]) % p;
  Inv[1] = sInv[1];
  for(int i = 2; i <= n; i++) Inv[i] = (1ll * sInv[i] * s[i - 1]) % p;
  ll tmp = k, ans = 0;
  /* for(int i = 1; i <= n; i++) cout << sInv[i] << ' ';
  cout << endl;
  for(int i = 1; i <= n; i++) cout << Inv[i] << ' ';
  cout << endl; */
  for(int i = 1; i <= n; i++) {
    ans += 1ll * tmp * Inv[i] % p;
    ans %= p;
    tmp = 1ll * tmp * k % p;
  }
  cout << ans << endl;//  98560
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  init();
  solve();
  return 0;
}