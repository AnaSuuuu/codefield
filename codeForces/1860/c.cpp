#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


void solve() {
  int n, ans = 0;
  cin >> n;
  vector<int> p(n + 1), f(n + 1), c(n + 1, 0);
  for(int i = 1; i <= n; i++) cin >> p[i];
  f[1] = 0;
  int minn = p[1];
  auto lowbit = [&](int x) {
    return x & (-x);
  };
  auto add = [&](int x) {
    for(int i = x; i <= n; i += lowbit(i)) {
      c[i]++;
    }
  };
  auto query = [&](int x) {
    int sum = 0;
    for(int i = x; i; i -= lowbit(i)) {
      sum += c[i];
    }
    return sum;
  };
  for(int i = 2; i <= n; i++) {
    int ok = 1;
    if(p[i] < minn) {
      minn = p[i];
      f[i] = 0;
      continue;
    }
    ok = query(p[i]);
    // cout << ok << endl;
    f[i] = (ok == 0);
    ans += f[i];
    if(f[i]) add(p[i]);
  }
  cout << ans << endl;
  return ;
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