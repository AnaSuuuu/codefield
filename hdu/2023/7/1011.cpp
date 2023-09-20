#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
  ll x, a, b, ans = 0;
  cin >> x >> a >> b;
  while(x != 0) {
    ll d1 = x - 1, d2 = (x + a) / 2, d3 = sqrt(x + b);
    x = min(min(d1, d2), d3);
    ans++;
  }
  cout << ans << endl;
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