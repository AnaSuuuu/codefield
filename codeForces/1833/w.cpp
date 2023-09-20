#include<bits/stdc++.h>
using namespace std;
int a[10];
int main() {
  freopen("D.in", "w", stdout);
  puts("24");
  a[1] = 1, a[2] = 2, a[3] = 3, a[4] = 4;//, a[5] = 5;
  int t = 24;
  while(t--) {
    puts("4");
    for(int i = 1; i <= 4; i++) cout << a[i] << ' ' ;
    cout << endl;
    next_permutation(a + 1, a + 1 + 4);
  }
}