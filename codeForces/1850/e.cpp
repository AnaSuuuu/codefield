#include<bits/stdc++.h>
using i64 = long long;
typedef long long ll;
using namespace std;

const int N = 2e5 + 5;
ll s[N];

void solve() {
  ll n, k, tmp1 = 0, tmp2 = 0;
  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    cin >> s[i];
    tmp1 += s[i];
    tmp2 += s[i] * s[i];
  }
  ll a = 4 * n, b = 4 * tmp1, c = tmp2 - k;
  cout << a << ' ' << b << ' ' << c << endl;
  ll del = 1ll * b * b - 4 * a * c;
  cout << del << endl;
  cout << (b * b - 4 * a * c >= 0) << endl;
  // ll ans = (sqrt(b * b - 4 * a * c) - b) / (2 * a)
  // cout << ans << endl;
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