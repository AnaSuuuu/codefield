#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 2e5 + 6;
const int mod = 1e9 + 7;
ll a[N], b[N];

void solve() {
  ll n;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) cin >> b[i];
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + n);
  ll ind = n, cnt = 0, ans = 1;
  for(ll i = n; i >= 1; i--) {
    while(a[ind] > b[i] && ind > 0) {
      ind--, cnt++;
    }
    ans *= (cnt - (n - i));
    ans %= mod;
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