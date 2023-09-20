#include<bits/stdc++.h>

void solve() {
  int x, k;
  std::cin >> x >> k;
  if(x % k) {
    std::cout << "1\n" << x << "\n";
    return ;
  }
  for(int i = x - 1; i >= 1; i--) {
    if(i % k && (x - i) % k) {
      std::cout << "2\n" << i << ' ' << x - i << "\n";
      return ;
    } 
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}