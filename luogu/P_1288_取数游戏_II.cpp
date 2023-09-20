#include <bits/stdc++.h>

int a[25];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, pos1, pos2;
  std::cin >> n;
  for(int i = 1; i <= n; i++) std::cin >> a[i];
  for(int i = 1; i <= n; i++) 
    if(a[i] == 0) {
      pos1 = i;
      break;
    }
  for(int i = n; i >= 1; i--) {
    if(a[i] == 0) {
      pos2 = i;
      break;
    }
  }
  if(((n - pos2) & 1) | ((pos1 - 1) & 1)) std::cout << "YES\n";
  else std::cout << "NO\n";
  return 0;
}