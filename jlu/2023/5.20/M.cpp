#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int a[N];
map<int, int> M;
int main() {
  freopen("M.in", "r", stdin);
  freopen("M.out", "w", stdout);
  int t;
  scanf("%d", &t);
  while(t--) {
    M.clear();
    int n, minn = 0x3f3f3f3f;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      minn = min(minn, a[i]);
      M[a[i]] = 1;
    }
    if(minn != 0) {
      puts("Yes");
      continue;
    }
    int kdl = 0;
    for(int i = 1; i <= n; i++) {
      if(M[i] == 0) {
        kdl = i;
        break;
      }
    }
    if(kdl == n) {
      puts("No");
      continue;
    }
    if(M[kdl + 1] == 0) {
      puts("Yes");
      continue;
    }
    int l = n + 1, r = 0;
    for(int i = 1; i <= n; i++) {
      if(a[i] == kdl + 1) l = min(l, i), r = max(r, i);
    }
    for(int i = l; i <= r; i++) a[i] = kdl;
    M.clear();
    for(int i = 1; i <= n; i++) M[a[i]] = 1;
    for(int i = 0; i <= n; i++) {
      if(M[i] == 0) {
        if(i == kdl + 1){
          puts("Yes");
          break;
        }
        else {
          puts("No");
          break;
        }
      }
    }
  }
  return 0;
}