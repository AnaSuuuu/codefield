#include <bits/stdc++.h>

std::string s0 = "codeforces";

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while(t--) {
    int ans = 0;
    std::string s;
    std::cin >> s;
    for(int i = 0; i < 10; i++) 
      ans += (s[i] != s0[i]);
    std::cout << ans << "\n"; 
  }
}