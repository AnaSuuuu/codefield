#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {  
  string s;
  ll n, k, tot = 0;
  cin >> n >> k;
  cin >> s;
  for(int i = 1; i < n; i++) {
    if(s[i] == '0' && s[i - 1] == '1') tot++;
  }
  if(n == 1) {
    cout << (1 ^ (k & 1)) << endl;
    return ;
  }
  if(tot == 0 && k == 1) {
    for(int i = 1; i < n; i++) cout << '1';
    cout << '0' << endl;  
    return ;
  }
  if(k >= tot) {
    for(int i = 1; i <= n; i++) cout << '1';
    cout << endl;
    return ;
  }
  int beg = 1, conse = 0;
  for(int i = 1; k && i < n; i++) {
    if(s[i] == '0') {
      conse++;
      if(s[i - 1] == '1') beg = i;  
    }
    else {
      if(conse == 0) continue;
      k--;
      // cout << beg << ' ' << beg + conse << endl;
      for(int j = beg; j < beg + conse; j++) s[j] = '1';
      conse = 0;
    }
  }
  for(int i = 0; i < n; i++) cout << s[i];
  cout << endl;
}

int main(){
  // freopen("1002.in", "r", stdin);
  // freopen("1002_.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    solve();
  } 
  return 0;
}