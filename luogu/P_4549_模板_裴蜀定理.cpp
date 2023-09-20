#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  return ((b == 0) ? a : gcd(b, a % b));
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, ans, x;
  cin >> n;
  cin >> ans;
  ans = abs(ans);
  for(int i = 2; i <= n; i++) {
    cin >> x;
    x = abs(x);
    ans = gcd(x, ans);
  } 
  cout << ans << endl;
  return 0;
}