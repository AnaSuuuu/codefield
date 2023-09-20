#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 2e6 + 5;
ll f[N], num[N];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  num[0] = 0;
  for(ll i = 1; i <= 2000; i++) num[i] = 1ll * i * (i + 1) / 2;
  f[1] = 1;
  for(ll i = 2; i <= 2e6; i++) {
    ll sta = sqrt(i * 2), kdl;
    if(num[sta] < i) kdl = sta + 1;
    else kdl = sta;
    //if(i == 2) cout << kdl << endl;
    f[i] = f[num[kdl - 2] + (i - num[kdl - 1]) - 1] * (i != num[kdl - 1] + 1) + f[num[kdl - 2] + (i - num[kdl - 1])] * (i != num[kdl]) + 1ll * i * i;
    if(i != num[kdl - 1] + 1 && i != num[kdl]) {
      ll x = num[kdl - 2] + (i - num[kdl - 1]) - 1;
      f[i] -= f[num[kdl - 3] + (x - num[kdl - 2])];
    }
  }
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    cout << f[n] << endl;  
  }
}