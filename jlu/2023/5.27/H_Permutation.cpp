#include <bits/stdc++.h>
typedef long long ll;

const int N = 1e6 + 6;
int a[N], len[N], n;

bool cmp(int x, int y) {
  return x > y;
}

bool dfs(int lef, int pos) {
  if(lef == 0) return true;
  if(pos == n + 1) return false;
  int is_ok = 0;
  if(lef >= len[pos]) is_ok |= dfs(lef - len[pos], pos + 1);
  if(is_ok) return true;
  is_ok |= dfs(lef, pos + 1);
  if(is_ok) return true;
  return false;
}

void solve() {
  int tot = 0;
  int maxn, pos = 1;
  std::cin >> n;
  for(int i = 1; i <= n; i++) std::cin >> a[i];
  maxn = a[1];
  for(int i = 2; i <= n; i++) {
    if(a[i] > maxn) {
      maxn = a[i];
      len[++tot] = i - pos;
      pos = i;
    }
  }
  len[++tot] = n + 1 - pos;
  std::sort(len + 1, len + 1 + tot, cmp);
  //std::cout << tot << ' ' << len[1] << "\n";
  if(len[1] > n / 2) {
    std::cout << "No\n";
    return ;
  }
  if(dfs(n / 2 - len[1], 2)) {
    std::cout << "Yes\n";
    return ;
  }
  else std::cout << "Yes\n";
  return ;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(nullptr);

  bool multi_test = 1;
  int t = 1;
  if(multi_test) std::cin >> t;

  while(t--) {
    solve();
  }

  return 0;
}