#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int s[N];
int gcd(int a, int b){
  return (a %b == 0 ? b : gcd(b, a%b));
}
int main(){
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> s[i];
    /*if(n == 2 || n == 3){
      cout << abs(a[1] - a[n]) << endl;
      continue;
    }*/
    if(n == 1){
      cout << 0 << endl;
      continue;
    }
    int kdl = 0;
    for(int i = 1; i <= n / 2; i++) {
      if(abs(s[i] - s[n - i + 1]) == 0) continue;
      if(kdl == 0) kdl = abs(s[i] - s[n - i + 1]);
      else kdl = gcd(kdl, abs(s[i] - s[n - i + 1]));
    }
    cout << kdl << endl;
  }
  return 0;
}