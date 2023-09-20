#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
int a[N];
int main() {
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    if(n == 1) {
      puts("1");
      continue;
    }
    if(a[1] == n) {
      for(int i = 2; i <= n; i++) {
        if(a[i] == n - 1) {
          for(int j = i; j <= n; j++) printf("%d ", a[j]);
          if(i == n) {
            for(int j = 1; j <= i - 1; j++) printf("%d ", a[j]);
          }
          else {
            printf("%d ", a[i - 1]);
            for(int j = 1; j < i - 1; j++) printf("%d ", a[j]);
          }
          break;  
        }
      }
      puts("");
      continue;
    }
    if(a[n] == n) {
      for(int i = n - 1; i >= 1; i--) {
        if(a[1] >= a[i]) {
          printf("%d ", n);
          for(int j = n - 1; j > i; j--) printf("%d ", a[j]);
          for(int j = 1; j <= i; j++) printf("%d ", a[j]);
          puts("");
          break;
        }
      }
      continue;
    }
    if(a[2] == n) {
      for(int i = 2; i <= n; i++) printf("%d ", a[i]);
      printf("%d", a[1]);
      puts("");
      continue;
    }
    int kk;
    for(kk = 1; a[kk] != n; kk++);
    for(int i = kk - 2; i >= 1; i--) {
      if(a[1] >= a[i]) {
        for(int j = kk; j <= n; j++) printf("%d ", a[j]);
        for(int j = kk - 1; j > i; j--) printf("%d ", a[j]);
        for(int j = 1; j <= i; j++) printf("%d ", a[j]);
        puts("");
        break;
      }
    } 
  }
  return 0;
}