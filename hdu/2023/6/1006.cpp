#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 305;
int a[N], sum[N], vis[N];

void solve() {
  int n, ans = 0;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i - 1] + a[i];
  for(int i = 1; i <= n; i++) {
    int tmp = 0;
    for(int j = i; j <= n; j++) {
      tmp += a[j];
      int kdl = sqrt(tmp);
      if(kdl * kdl == tmp) ans++;
    }
  }
  // cout << ans << endl;
  int maxn = 0;
  for(int i = 1; i <= n; i++) {
    int M = 0, kdl = 0;
    memset(vis, 0, sizeof(vis));
    for(int l = 1; l <= i; l++) {
      for(int r = i; r <= n; r++) {
        int s = sum[r] - sum[l - 1];
        int R = sqrt(s + 300 - a[i]);
        int tmp = sqrt(s);
        if(tmp * tmp == s) kdl++;
        for(int j = tmp + 1; j <= R; j++) {
          vis[j * j - s]++;
          if(vis[j * j - s] > M) M = vis[j * j - s];
        }
      }
    }
    // cout << i << ' ' << M - kdl << endl; 
    maxn = max(maxn, M - kdl);
  }
  // cout << endl;
  for(int i = 1; i <= n; i++) {
    int M = 0, kdl = 0;
    memset(vis, 0, sizeof(vis));
    for(int l = 1; l <= i; l++) {
      for(int r = i; r <= n; r++) {
        int s = sum[r] - sum[l - 1];
        int L = sqrt(s - a[i] + 1);
        if(L * L != s - a[i] + 1) L++;
        int tmp = sqrt(s);
        if(tmp * tmp == s) kdl++;
        for(int j = L; j <= tmp; j++) {
          vis[s - j * j]++;
          if(vis[s - j * j] > M) M = vis[s - j * j];
        }
      }
    }
    // cout << i << ' ' << M - kdl << endl; 
    maxn = max(maxn, M - kdl);
  }
  // cout << maxn << endl;
  cout << max(ans, ans + maxn) << endl;
}

int main(){
  freopen("1006.in", "r", stdin);
  freopen("1006.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    solve();
  } 
  return 0;
}