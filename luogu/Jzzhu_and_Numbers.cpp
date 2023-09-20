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

  int t = 1;
  while(t--) {
    int n, k = 0, maxn = 0;
    cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> f(2, vector<int>(1e6 + 5, 0));
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
      //f[i % 2][a[i]] = 1;
      maxn = max(maxn, a[i]);
      //if(i == n) 
      //cout << f[n % 2][0] << endl;
      for(int j = 0; j <= maxn; j++) {
        f[i % 2][j] = 0;
        f[i % 2][j] += f[(i - 1) % 2][j];
        f[i % 2][j] %= mod;
        f[i % 2][j & a[i]] += f[(i - 1) % 2][j];
        f[i % 2][j & a[i]] %= mod;
        //if(i == n && j == 0) cout << f[(i - 1) % 2][j] << "AAA" << endl;
        //if(i == n && (j & a[i]) == 0) cout << f[(i - 1) % 2][j] << "BBB" << endl;
      }
      f[i % 2][a[i]]++;
    }
    //cout << f[(n - 1) % 2][0] << ' ' << f[(n - 1) % 2][1] << endl;
    cout << f[n % 2][0] << endl;
  }
}