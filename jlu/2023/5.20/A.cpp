#include<bits/stdc++.h>
using namespace std;
int main() {
  int n, cnt = 0;
  cin >> n;
  int l = 1, r = n, ans, kdl; 
  while(r >= l + 2) {
    int mid = l + r >> 1;
    printf("? %d\n", mid);
    fflush(stdout);
    cin >> kdl;
    if(kdl == cnt) {
      printf("! %d\n", mid);
      return 0;
    }
    int cnt1 = kdl;
    printf("? %d\n", l);
    fflush(stdout);
    cin >> kdl;
    if(cnt1 == kdl) {
      printf("! %d\n", l);
      return 0;
    }
    if(kdl == cnt) {
      l++, r = mid - 1;
    }
    else {
      l = mid + 1;
    }
    cnt = kdl;
  }
  if(r - l == 1) {
    printf("? %d\n", l);
    fflush(stdout);
    cin >> kdl;
    if(kdl == cnt) {
      printf("! %d\n ", l);
    }
    else printf("! %d\n", r);
    return 0;
  }
  printf("! %d", r);
  return 0;
}