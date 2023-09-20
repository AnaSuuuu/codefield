#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 505;
int k, n;
int f[N];

void solve() {
  // cin >> k >> n;
  k = 5;
  f[0] = 0;
  for(n = 1; n <= k; n++) f[n] = 1;
  f[k + 1] = 0;
  for(n = k + 2; n <= 500; ) {
    f[n] = 0;
    for(int i = 0; i <= n - k; i++) {
      if(f[i] ^ f[n - k - i]) {
        f[n] = 1;
        break;
      }
    }
    if(f[n] == 0) {
      for(int i = 1; i <= k; i++) f[i + n] = 1;
    }
    else n++;
  } 
  for(int i = 1; i <= 500; i++) 
    if(f[i] == 0) cout << i << endl;
}

int main(){
  freopen("1001.in", "r", stdin);
  freopen("1001.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    solve();
  } 
  return 0;
}