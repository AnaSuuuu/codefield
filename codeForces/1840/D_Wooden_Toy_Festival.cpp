#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int a[N], n;

bool check(int lim) {
  int num1 = a[1] + lim;
  if(upper_bound(a + 1, a + 1 + n, num1 + lim) - a > n) return true;
  else {
    int num2 = a[upper_bound(a + 1, a + 1 + n, num1 + lim) - a] + lim;
    if(upper_bound(a + 1, a + 1 + n, num2 + lim) - a > n) return true;
    else {
      int num3 = a[upper_bound(a + 1, a + 1 + n, num2 + lim) - a] + lim;
      // cout << lim << endl;
      // cout << num1 << ' ' << num2 << ' ' << num3 << endl;
      if(num3 + lim >= a[n]) return true;
      else return false;
    }
  }
}
 
int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    int l = 0, r = 0, ans;
    cin >> n;
    for(int i = 1; i <= n; i++)
      cin >> a[i];
    sort(a + 1, a + 1 + n);
    r = a[n] - a[1];
    //cout << l << ' ' << r << endl;
    while(l <= r) {
      int mid = (l + r) >> 1;
      if(check(mid)) {
        r = mid - 1;
        ans = mid;
      }
      else l = mid + 1;
    }
    cout << ans << endl;
  }
  return 0;
}