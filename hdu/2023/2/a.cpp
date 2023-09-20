#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1005;
int a[N];
ll cal(ll x) {
  ll num = 1;
  while(x >= 1) {
    num *= x;
    x--;
  }
  return num;
}

void solve() {
  ll n, tot, maxn = 0, ans;
  cin >> n;
  tot = cal(n);
  for(int i = 1; i <= n; i++) a[i] = i;
  if(int(n / exp(1)) == round(n / exp(1))) {
    cout << int(n / exp(1)) << endl;
    return ;
  }
  for(int i = int(n / exp(1)); i <= round(n / exp(1)); i++) {
    int tmp = 0;
    for(int j = 1; j <= cal(n); j++) {
      for(int k = 1; k <= n; k++) {
        int x = -1, t;
        for(t = 1; t <= i; t++) x = max(x, a[t]);
        for(t = i + 1; t < n; t++) {
          if(a[t] > x) break;
        }
        tmp += (a[t] == n);
      }
      next_permutation(a + 1, a + 1 + n); 
    }
    if(tmp > maxn) maxn = tmp, ans = i;
  }
  cout << ans << endl;
}

int main(){
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}