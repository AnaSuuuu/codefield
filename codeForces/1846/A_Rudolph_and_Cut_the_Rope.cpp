#include<bits/stdc++.h>
using namespace std;

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
      int a, b;
      cin >> a >> b;
      ans += (a > b);
    }
    cout << ans << endl;
  } 
  return 0;
}