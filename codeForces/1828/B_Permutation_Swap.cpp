#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 6;
int p[N];

int gcd(int a, int b) {
  return ((b == 0) ? a : gcd(b, a % b));
}

void solve() {
  int n, ans;
  cin >> n;
  cin >> p[1];
  ans = abs(p[1] - 1);
  for(int i = 2; i <= n; i++) {
    cin >> p[i];
    ans = gcd(ans, abs(p[i] - i));
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