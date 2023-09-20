#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
  ll m, k, a, b, ans = 0;
  cin >> m >> k >> a >> b;
  ll na = a, nb = b;
  if(m >= nb * k) m -= nb * k;
  else m %= k;
  if(na >= m % k) {
    na -= m % k;
    m = m / k * k; // cout << m << ' ' << na << endl;
    m -= (na / k * k);
    m = max(m, 0ll);
    na = 0;
    
  }
  else {
    m -= na;
    na = 0;
    ans += (m % k);
  }
  cout << m / k + ans << endl;
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