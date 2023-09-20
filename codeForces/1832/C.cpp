#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int a[N], b[N];
int main(){
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int t;
  cin >> t;
  while(t--) {
    int n, tot = 2;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(n == 1) {
      puts("1");
      continue;
    }
    int kdl = 1;
    b[1] = a[1];
    for(int i = 2; i <= n; i++) {
      if(a[i] != a[i - 1]) b[++kdl] = a[i];
    }
    //cout << kdl << endl;
    //for(int i = 1; i <= kdl; i++) cout << b[i] << ' ';
    //cout << endl;
    if(kdl == 1) {
      puts("1");
      continue;
    }
    for(int i = 2; i < kdl; i++) {
      if(b[i] > b[i - 1] && b[i] > b[i + 1]) tot++;
      if(b[i] < b[i - 1] && b[i] < b[i + 1]) tot++;
    }
    if(tot == 2 && b[1] == b[kdl]) {
      puts("1");
      continue;
    }
    cout << tot << endl;
  }
  return 0;
}