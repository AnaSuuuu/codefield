#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
//string s;
int main() {
  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);
  int t;
  scanf("%d", &t);
  while(t--) {
    ll ans;
    string s;
    //s.clear();
    cin >> s;
    //puts("AAA");
    bool ok = 1;
    int n = s.length();
    for(int i = 0; i < n; i++) {
      if(s[i] == '0') {
        ok = 0;
        break;
      }
    }
    if(ok) {
      printf("%lld\n", 1ll * n * n);
      continue;
    }
    //cout << n << endl;
    //for(int i = 0; i < n; i++) 
    //  s[n + i] = s[i];
    int len = 0, maxn = 0;
    //cout << n << endl;
    for(int i = 0; i < 2 * n; i++) {
      if(s[i % n] == '0') {
        maxn = max(maxn, len);
        len = 0;
      }
      else len++;
    }
    maxn = max(maxn, len);
    maxn = min(maxn, n);
    printf("%lld\n", 1ll * (maxn + 1) / 2 * (maxn + 1 - (maxn + 1) / 2));/**/
  }
  return 0;
}