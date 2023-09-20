#include <bits/stdc++.h>

const int N = 105;
int a[N];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while(t--) {
    int n, tmp = 0, ans = 0;
    std::cin >> n;
    for(int i = 1; i <= n; i++) std::cin >> a[i]; 
    for(int i = 1; i <= n; i++) {
      if(a[i] == 1) ans = std::max(ans, tmp), tmp = 0;
      else tmp++;
    }
    std::cout << std::max(ans, tmp) << "\n";
  }
}