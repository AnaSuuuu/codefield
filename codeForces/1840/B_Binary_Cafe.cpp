#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int lowbit(int x) {
  return x & (-x);
}
int work(int x) {
  int tmp = 0;
  while(x) {
    tmp = lowbit(x);
    x -= lowbit(x);
  }
  return tmp;
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ll t;
  cin >> t;
  while(t--) {
    ll n, k;
    cin >> n >> k;
    if(k <= 31 && (1ll << (k)) - 1 <= n)
      cout << (1 << k) << endl;
    else {
      // cout << "AAA" << endl;
      ll ans = 0;
      while(n) {
        ans += work(n);
        n -= work(n);
      }
      cout << ans + 1 << endl;
    }
  }
  return 0;
}