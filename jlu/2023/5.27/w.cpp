#include<bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(nullptr);
  srand(time(NULL));

  freopen("w.out", "w", stdout);
  int n = rand();
  std::cout << n % 100 << "\n";
  for(int i = 1; i <= n % 100; i++) std::cout << rand() << " \n"[i == n % 100 - 1];
  std::cout << rand() << " " << rand() << " " << rand() << " ";  
  return 0;
}