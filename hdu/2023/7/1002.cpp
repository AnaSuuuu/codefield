#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int mod = 998244353;
const int N = 1e5 + 5;
int a[N];

inline ll qpow(ll a, ll b, ll p) {
  ll ans = 1;
  while (b) {
    if (b & 1) ans = ans % p * a % p;
    a = a % p * a % p;
    b >>= 1;
  }
  return ans;
}
ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a % b);
}
inline ll inv(ll a, ll p) {
  return qpow(a, p - 2, p);
}

void solve() {
  ll n, q, p, x, y;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];  
  if(a[1] == 1) x = 1;
  else if(a[1] == 0) x = 0;
  else x = 499122177;
  
  for(int i = 2; i <= n; i++) {
    if(a[i] == 1) y = 1;
    else if(a[1] == 0) y = 0;
    else y = 499122177;
    x = x + y - 2 * x * y;
    x = (x % mod + mod) % mod;
  } 
  cout << x << endl;
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