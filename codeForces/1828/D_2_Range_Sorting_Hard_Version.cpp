#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 3e5 + 5;
ll a[N], ans, f[25][N], r[N], l[N];

void solve() {
  int n;
  ans = 0;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    f[0][i] = a[i];
    ans += 1ll * (i - 1) * (n - i + 1);
  }
  for(int i = 1; i <= 20; i++) {
    for(int j = 1; j + (1 << i) - 1 <= n; j++)
      f[i][j] = max(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
  }
  stack<ll> s;
  for(int i = n; i >= 1; i--) {
    while(s.size() && a[s.top()] > a[i]) s.pop();
    r[i] = s.size() ? s.top() : (n + 1);
    s.push(i); 
  }
  // for(int i = 1; i <= n; i++) cout << r[i] << ' ';
  // cout << endl;
  while(s.size()) s.pop();
  for(int i = 1; i <= n; i++) {
    while(s.size() && a[s.top()] > a[i]) s.pop();
    int kdl = s.size() ? s.top() : 0;
    // cout << kdl << ' ';
    for(int j = 20; j >= 0; j--) {
      if(kdl > (1 << j) && f[j][kdl - (1 << j)] < a[i]) kdl -= (1 << j);  
    }
    // cout << kdl << endl;
    if(s.size()) ans -= 1ll * (s.top() - kdl + 1) * (r[i] - i);
    s.push(i);
  }/**/
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