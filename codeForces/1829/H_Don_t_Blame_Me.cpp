#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;

int lowbit(int x) {
  return x & (-x);
}
int count(int x) {
  int num = 0;
  while(x) {
    x -= lowbit(x);
    num++;
  }
  return num;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<vector<int>> f(n + 1, vector<int>(1 << 6, 0));
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
      f[i][a[i]] = 1;
      for(int j = 0; j < (1 << 6); j++) {
        f[i][j] += f[i - 1][j];
        f[i][j] %= mod;
        f[i][j & a[i]] += f[i - 1][j];
        f[i][j & a[i]] %= mod;
      }
    }
    int ans = 0;
    // cout << n << ' ' << k << endl;
    // cout << f[n][2] << endl;
    // cout << f[n][0] << ' ' << f[n - 1][4] << endl;;
    for(int i = 0; i < (1 << 6); i++) {
      if(count(i) == k) ans += f[n][i], ans %= mod;
    }
    cout << ans << endl;
  }
}