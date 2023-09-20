#include<bits/stdc++.h>

void solve() {
  std::string s;
  std::cin >> s;
  int n = s.length();
  char c;
  if(s[0] == '?') s[0] = '0', c = '0';
  else c = s[0];
  if(s[n - 1] == '?') s[n - 1] = '1';
  for(int i = 1; i < n - 1; i++) {
    if(s[i] == '?') {
      if(s[i - 1] == '0') s[i] = '0';
      else s[i] = '1';
    }  
  }
  std::cout << s << "\n";
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