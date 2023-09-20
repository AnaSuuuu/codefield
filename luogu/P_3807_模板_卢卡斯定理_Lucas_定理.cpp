#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1e5 + 5;
ll n, m, p;
ll a[N];

void init() {
  cin >> n >> m >> p;
  a[0] = 1;
  for(int i = 1; i <= p; i++) a[i] = 1ll * a[i - 1] * i % p;
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

ll c(ll n, ll m) {
  return ((m > n) ? 0 : (a[n] * inv(a[m], p) % p * inv(a[n - m], p) % p));
}

ll Lucas(ll n, ll m) {
  return ((m == 0) ? 1 : (c(n % p, m % p) % p * Lucas(n / p, m / p) % p));
}

void solve() {
  init();
  cout << Lucas(n + m, m) % p << endl;
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    solve();
    /* cout << (n + m) / p << ' ' << m / p << endl;
    cout << c(1, 1) << endl;
    cout << Lucas(1, 1) % p << endl; */
  } 
  return 0;
}