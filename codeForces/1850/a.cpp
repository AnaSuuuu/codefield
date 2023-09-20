#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if(a > b) a ^= b ^= a ^= b;
  if(a > c) a ^= c ^= a ^= c;
  // cout << b << ' ' << c << endl;
  cout << (b + c >= 10 ? "YES" : "NO") << endl;
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    solve();
  } 
  return 0;
}