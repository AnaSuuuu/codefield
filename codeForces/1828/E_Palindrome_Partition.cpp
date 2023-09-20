#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 5e5 + 5;
char s1[N << 1], s2[N << 1];
int n, len[N << 1], nxt[N], pre[N], m;
int f[N], g[N];

void update() {
  s2[0] = s2[1] = '#';
  for(int i = 1; i <= n; i++) {
    s2[i << 1] = s1[i];
    s2[i << 1 | 1] = '#';
  }
  m = 2 * n + 1;
}

void manacher() {
  update();
  int maxr = 0, mid = 0;
  for(int i = 1; i <= m; i++) {
    len[i] = 0;
    if(i < maxr) len[i] = min(len[(mid << 1) - i], len[mid] + mid - i);
    else len[i] = 1;
    while(i + len[i] <= m &&  i - len[i] > 0 && s2[i + len[i]] == s2[i - len[i]]) len[i]++;
    if(len[i] + i > maxr) {
      maxr = len[i] + i;
      mid = i; 
    } 
  }
}

void solve() {
  cin >> n >> s1 + 1;
  manacher();
  for(int i = 1; i <= n; i++) {
    nxt[i] = i + 1;
    pre[i] = i - 1;
    f[i] = 0;
  }
  /*for(int i = n - 2; i >= 1; i -= 2) {

  }*/
  /* for(int i = 1; i <= m; i++) cout << s2[i] << ' ';
  cout << endl;
  for(int i = 1; i <= m; i++) cout << len[i] << ' ';
  cout << endl;
  for(int i = 1; i <= m; i++) cout << i << ' ';
  cout << endl; */
  for(int i = m - 2; i >= 3; i -= 2) {
    int l = i + 1 >> 1, r = (i >> 1) + (len[i] - 1 >> 1);
    // cout << i << ' ' << l << ' ' << r << endl;/**/
     for(int j = l; j <= r; j = nxt[j]) {
      // cout << j << endl;
      f[j] = (j - (i >> 1)) << 1;
      nxt[pre[j]] = nxt[j];
      pre[nxt[j]] = pre[j];
    } 
  } /**/
  // for(int i = 1; i <= n; i++) cout << f[i] << ' ';
  // cout << endl;
  ll ans = 0;
  for(int i = 1; i <= n; i++) {
    if(f[i] == 0) g[i] = 0;
    else g[i] = g[i - f[i]] + 1;
    ans += g[i];
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