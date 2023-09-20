#include<bits/stdc++.h>

void solve() {
  int n;
  std::string s;
  std::cin >> n;
  std::cin >> s;
  int cnt1 = 0, cnt2 = 0, ans = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == '<') {
      cnt1++;
      ans = std::max(ans, cnt2);
      cnt2 = 0;
    }
    else {
      cnt2++;
      ans = std::max(ans, cnt1);
      cnt1 = 0;
    }
  }
  ans = std::max(ans, std::max(cnt1, cnt2));
  std::cout << ans + 1 << "\n";
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