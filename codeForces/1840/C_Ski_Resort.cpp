#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 2e5 + 5;
int a[N];

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    ll n, k, q, ans = 0, l = -1, r = -1;
    cin >> n >> k >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
      if(a[i] <= q) {
        if(l == -1) l = i, r = i;
        else r++;
      }
      else {
        if(l != -1) {
          ll len = (r - l + 1) - k + 1;
          //cout << len << endl;
          if(len > 0) ans += (len + 1) * len / 2;
        }
        l = -1;
      }
      //cout << l << ' ' << r << endl;
    }
    //cout << l << ' ' << r << ' ' << q << endl;
    if(l != -1) {
      ll len = (r - l + 1) - k + 1;
      if(len > 0) ans += (len + 1) * len / 2;
    }
    cout << ans << endl;
  }
  return 0;
}