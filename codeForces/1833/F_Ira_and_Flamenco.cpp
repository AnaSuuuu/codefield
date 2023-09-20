#include<bits/stdc++.h>
#define ll long long

const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int a[N];
std::map<int, int> cnt;

ll quick_mul(ll a, ll b) {
  ll x = 1;
  while(b) {
    if(b & 1) x *= a;
    x %= mod;
    a = (a * a) % mod;
    b >>= 1; 
  }
  return x;
}

void solve() {
  int n, m;
  cnt.clear();
  std::cin >> n >> m;
  //std::cout << n << ' ' << m << std::endl;
  for(int i = 1; i <= n; i++) std::cin >> a[i], cnt[a[i]]++;
  int las = -1, miss = -1;
  ll kdl = 1, ans = 0;
  for(auto &it: cnt) {
    int x = it.first, y = it.second;
    //std::cout << x << ' ' << y << std::endl;
    if(las != x - 1) {
      miss = x - 1;
      kdl = 1;
    }
    kdl *= y;
    kdl %= mod;
    if(x - miss > m) {
      kdl *= quick_mul(cnt[x - m], mod - 2);
      kdl %= mod;
      //ans %= mod;
    }
    if(x - miss >= m) {
      ans += kdl;
      ans %= mod;
    }
    las = x;
  }
  std::cout << ans << std::endl;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}