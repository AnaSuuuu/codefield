#include <bits/stdc++.h>

const int N = 105;
int a[N];

bool judge(int x, int y) {
  if(y * 3 == x || y == x) return true;
  if(y % 2 == 0 && y / 2 * 3 == x) return true;
  if(y / 2 * 3 > x) return false;
  if(x % 3) return false;
  return judge(x / 3, y) | judge(x / 3 * 2, y);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while(t--) {
    int n, m;
    std::cin >> n >> m;
    std::cout << (judge(n, m) ? "YES" : "NO") << "\n";
  }
}