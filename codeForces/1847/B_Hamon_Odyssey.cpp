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
    int n, lim, ans;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    lim = a[1];
    for(int i = 2; i <= n; i++) lim &= a[i];
    // cout << lim << endl;
    if(lim != 0) {
      cout << "1" << endl;
      continue;
    }
    lim = a[1], ans = 0;
    for(int i = 1; i <= n; i++) {
      lim &= a[i];
      if(lim == 0) {
        ans++;
        lim = (1 << 30) - 1;
      }
    }
    // cout << ans << ' ' << lim << endl;
    // if(lim != 0 && (lim != (1 << 30) - 1)) ans--;
    cout << ans << endl;
  } 
  return 0;
}