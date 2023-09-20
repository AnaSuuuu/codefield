#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 5e3 + 5;
ll a[N], maxn[N], l[N];

void solve() {
  ll n, ans = 0;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) {
    int cnt = 0, tmp = 0;
    for(int j = i; j <= n; j++) {
      if(a[j] > maxn[cnt]) {
        maxn[++cnt] = a[j];
        l[cnt] = j;
      }
      else {
        if(a[j] < maxn[cnt - 1]) {
          tmp++;
          int kdl = maxn[cnt--];
          while(a[j] < maxn[cnt] && cnt > 0) {
            tmp++;
            cnt--;
          }
          maxn[++cnt] = kdl;
        }
        else tmp++;
      }
      ans += tmp;
    }
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

