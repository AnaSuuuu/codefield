#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
int vis[2];
int main() {
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    int lim = a[1] % 2, ok = 1;
    memset(vis, 0x3f, sizeof(vis));
    vis[a[1] % 2] = a[1];
    for(int i = 2; i <= n; i++) {
      if(a[i] % 2 != lim) {
        if(vis[1] == 0x3f3f3f3f || vis[1] == a[i]) {
          ok = 0;
          break;
        }
      }
      vis[a[i] % 2] = min(vis[a[i] % 2], a[i]);
      if(!ok) break;  
    }
    if(ok) puts("YES");
    else puts("NO");
  }
  return 0;
}