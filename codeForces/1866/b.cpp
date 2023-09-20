#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int M = 2e6 + 5, N = 1e5 + 5;
const int mod = 998244353;
ll a[N], b[N], c[N], d[N];
ll cnt[M];

ll qpow(ll b) {
  ll x = 1, a = 2;
  while(b) {
    if(b & 1) x = (x * a) % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return x;
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ll n, m, ans = 1, kk = 0;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) cin >> b[i], cnt[a[i]] = b[i];
  cin >> m;
  for(int i = 1; i <= m; i++) cin >> c[i];
  for(int i = 1; i <= m; i++) {
    cin >> d[i], cnt[c[i]] -= d[i];
    if(cnt[c[i]] < 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  for(int i = 1; i <= n; i++) {
    if(cnt[a[i]] != 0) kk++;
  }
  cout << kk << endl;
  cout << qpow(kk) << endl;
  return 0;
}