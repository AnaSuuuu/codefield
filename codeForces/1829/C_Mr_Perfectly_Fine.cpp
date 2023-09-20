#include <bits/stdc++.h>

const int N = 105;
int a[N];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while(t--) {
    int n, cos1 = 0x3f3f3f3f, cos2 = 0x3f3f3f3f, cos3 = 0x3f3f3f3f;
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
      int m, x;
      std::cin >> m >> x;
      if(x == 11) cos1 = std::min(cos1, m);
      else if(x == 10) cos2 = std::min(cos2, m);
      else if(x == 1) cos3 = std::min(cos3, m); 
    }
    int ans = std::min(cos1, cos2 + cos3);
    std::cout << (ans == 0x3f3f3f3f ? -1 : ans) << "\n";
  }
}