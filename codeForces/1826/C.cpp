#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int t;
  scanf("%d", &t);
  while(t--){
    int n, m, ok = 0;
    scanf("%d%d", &n ,&m);
    if(n == 1){
      puts("YES");
      continue;
    }
    if(n <= m){
      puts("NO");
      continue;
    }
    for(int i = 2; i * i <= n && i <= m; i++){
      if(n % i == 0) {
        ok = 1;
        break;
      }
    }
    if(ok) puts("NO");
    else puts("YES");
  }
  return 0;
}