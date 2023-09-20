#include <bits/stdc++.h>

struct Node {
  int id, num;
} r[1005], c[1005];

bool cmp(Node x, Node y) {
  return x.num > y.num;
}
bool cmp1(Node x, Node y) {
  return x.id < y.id;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int m, n, k, l, d;
  std::cin >> m >> n >> k >> l >> d;
  for(int i = 1; i <= n; i++) r[i].id = i;
  for(int i = 1; i <= m; i++) c[i].id = i;
  for(int i = 1; i <= d; ++i) {
    int x, y, p, q;
    std::cin >> x >> y >> p >> q;
    if(x == p) r[std::min(y, q)].num++;
    else c[std::min(x, p)].num++;
  }
  //std::cout << c[1].num << "\n";
  std::sort(r + 1, r + 1 + n, cmp);
  std::sort(c + 1, c + 1 + m, cmp);
  std::sort(r + 1, r + 1 + l, cmp1);  
  std::sort(c + 1, c + 1 + k, cmp1);
  for(int i = 1; i <= k; i++) std::cout << c[i].id << " \n"[i == k];
  for(int i = 1; i <= l; i++) std::cout << r[i].id << " \n"[i == l];

  return 0;
}